#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
bool isHexadecimal(string str);
int decimalPoint(string str);
double calculationInitial(string str);
string calculationFinal(string str);
int main()
{
    string hexadecimalNumber;
    cout << "Hexadecimal Number:";
    do
    {
        cin >> hexadecimalNumber;
    } while (!isHexadecimal(hexadecimalNumber) && cout << "Enter correct hexadecimal number:");
    cout << "Binary Number:" << calculationFinal(hexadecimalNumber) << endl;
    system("pause");
    return 0;
}
bool isHexadecimal(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != 'A' && str[i] != 'B' && str[i] != 'C' && str[i] != 'D' && str[i] != 'E' && str[i] != 'F' && str[i] != 'a' && str[i] != 'b' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e' && str[i] != 'f' && str[i] != '.')
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
        int n;
        if (i == decimalPoint(str))
            continue;
        else if (str[i] >= '0' && str[i] <= '9')
            n = str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'F')
            n = str[i] - 55;
        else if (str[i] >= 'a' && str[i] <= 'f')
            n = str[i] - 87;
        decimalNumber += n * pow(16, countPower);
        countPower--;
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