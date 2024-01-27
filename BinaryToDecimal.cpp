#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isBinary(string str);
int decimalPoint(string str);
double calculation(string str);
int main()
{
    string binaryNumber;
    cout << "Binary Number:";
    do
    {
        cin >> binaryNumber;
    } while (!isBinary(binaryNumber) && cout << "Enter correct binary number:");
    cout << "Decimal Number:" << calculation(binaryNumber) << endl;
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
double calculation(string str)
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