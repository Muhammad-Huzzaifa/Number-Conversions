#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isOctal(string str);
int decimalPoint(string str);
double calculation(string str);
int main()
{
    string octalNumber;
    cout << "Octal Number:";
    do
    {
        cin >> octalNumber;
    } while (!isOctal(octalNumber) && cout << "Enter correct octal number:");
    cout << "Decimal Number:" << calculation(octalNumber) << endl;
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
            decimalNumber += n * pow(8, countPower);
            countPower--;
        }
    }
    return decimalNumber;
}