#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
bool isBinary(string str);
int decimalPoint(string str);
double calculationInitial(string str);
string calculationFinal(string str);
int main()
{
    string binaryNumber;
    cout << "Binary Number:";
    do
    {
        cin >> binaryNumber;
    } while (!isBinary(binaryNumber) && cout << "Enter correct binary number:");
    cout << "Hexadecimal Number:" << calculationFinal(binaryNumber) << endl;
    system("pause");
    return 0;
}
bool isBinary(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '.')
        {
            return false;
        }
    }
    return true;
}
int decimalPoint(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            return i;
        }
    }
    return str.length();
}
double calculationInitial(string str)
{
    double decimalNumber{0};
    int countPower{decimalPoint(str) - 1};
    for (int i = 0; i < str.length(); i++)
    {
        if (i == decimalPoint(str))
            continue;
        else
        {
            int n = str[i] - '0';
            decimalNumber += n * pow(2, countPower);
            countPower--;
        }
    }
    return decimalNumber;
}
string calculationFinal(string str)
{
    double number = calculationInitial(str);
    ostringstream stream;
    stream << number;
    string decimalNumber = stream.str();
    string beforePoint{NULL}, afterPoint{NULL}, hexadecimalNumber{NULL};
    if (decimalPoint(decimalNumber) != decimalNumber.length())
    {
        beforePoint = decimalNumber.substr(0, decimalPoint(decimalNumber));
        afterPoint = decimalNumber.substr(decimalPoint(decimalNumber) + 1);
        int numberBeforePoint{stoi(beforePoint)};
        double numberAfterPoint{(stoi(afterPoint)) * 1.0}, number{1};
        for (int i = 0; i < afterPoint.length(); i++)
            number *= 10;
        numberAfterPoint /= number;
        while (numberBeforePoint != 0)
        {
            int n = numberBeforePoint % 16;
            if (n >= 10)
                hexadecimalNumber = static_cast<char>(n + 55) + hexadecimalNumber;
            else
                hexadecimalNumber = to_string(n) + hexadecimalNumber;
            numberBeforePoint /= 16;
        }
        hexadecimalNumber += '.';
        while (numberAfterPoint > 0 && hexadecimalNumber.length() < 32)
        {
            numberAfterPoint *= 16;
            int n = numberAfterPoint;
            if (n >= 10)
                hexadecimalNumber += static_cast<char>(n + 55);
            else
                hexadecimalNumber += to_string(n);
            numberAfterPoint -= n;
        }
    }
    else
    {
        beforePoint = decimalNumber.substr(0, decimalPoint(decimalNumber));
        int number{stoi(beforePoint)};
        while (number != 0)
        {
            int n = number % 16;
            if (n >= 10)
                hexadecimalNumber = static_cast<char>(n + 55) + hexadecimalNumber;
            else
                hexadecimalNumber = to_string(n) + hexadecimalNumber;
            number /= 16;
        }
    }
    return hexadecimalNumber;
}