#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
bool isOctal(string str);
int decimalPoint(string str);
double calculationInitial(string str);
string calculationFinal(string str);
int main()
{
    string octalNumber;
    cout << "Octal Number:";
    do
    {
        cin >> octalNumber;
    } while (!isOctal(octalNumber) && cout << "Enter correct octal number:");
    cout << "Binary Number:" << calculationFinal(octalNumber) << endl;
    system("pause");
    return 0;
}
bool isOctal(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '.')
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
            decimalNumber += n * pow(8, countPower);
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
    string beforePoint{NULL}, afterPoint{NULL}, binaryNumber{NULL};
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
            int n = numberBeforePoint % 2;
            binaryNumber = to_string(n) + binaryNumber;
            numberBeforePoint /= 2;
        }
        binaryNumber += '.';
        while (numberAfterPoint > 0 && binaryNumber.length() < 32)
        {
            numberAfterPoint *= 2;
            if (numberAfterPoint >= 1)
            {
                binaryNumber += '1';
                numberAfterPoint -= 1;
            }
            else
                binaryNumber += '0';
        }
    }
    else
    {
        beforePoint = decimalNumber.substr(0, decimalPoint(decimalNumber));
        int number{stoi(beforePoint)};
        while (number != 0)
        {
            int n = number % 2;
            binaryNumber = to_string(n) + binaryNumber;
            number /= 2;
        }
    }
    return binaryNumber;
}