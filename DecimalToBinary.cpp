#include <iostream>
#include <string>
using namespace std;
bool isDecimal(string str);
int decimalPoint(string str);
string calculation(string str);
int main()
{
    string decimalNumber;
    cout << "Decimal Number:";
    do
    {
        cin >> decimalNumber;
    } while (!isDecimal(decimalNumber) && cout << "Enter correct decimal number:");
    cout << "Binary Number:" << calculation(decimalNumber) << endl;
    system("pause");
    return 0;
}
bool isDecimal(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.')
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
string calculation(string str)
{
    string beforePoint{NULL}, afterPoint{NULL}, binaryNumber{NULL};
    if (decimalPoint(str) != str.length())
    {
        beforePoint = str.substr(0, decimalPoint(str));
        afterPoint = str.substr(decimalPoint(str) + 1);
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
        beforePoint = str.substr(0, decimalPoint(str));
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