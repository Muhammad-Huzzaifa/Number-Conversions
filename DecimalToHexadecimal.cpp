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
    cout << "Hexadecimal Number:" << calculation(decimalNumber) << endl;
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
    string beforePoint{NULL}, afterPoint{NULL}, hexadecimalNumber{NULL};
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
        beforePoint = str.substr(0, decimalPoint(str));
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