#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> readCardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int> number);
int getSize(vector<int> number);
int sumOfOddPlace(vector<int> number);
int getDigit(int number);
int sumOfDoubleEvenPlace(vector<int> number);
bool isValid(vector<int> number);

int main()
{
    vector<int> number = readCardNumber();
    
    if (isValid(number)) {
        cout << "\nResult: The credit card number is VALID.\n";
    } else {
        cout << "\nResult: The credit card number is INVALID.\n";
    }

    cout << "--------------------------------\n";
    cout << "Size: " << getSize(number) << "\n";
    cout << "Prefix Matched: " << (prefixMatched(number) ? "Yes" : "No") << "\n";
    cout << "Sum of Odd Places: " << sumOfOddPlace(number) << "\n";
    cout << "Sum of Double Even Places: " << sumOfDoubleEvenPlace(number) << "\n";
    
    return 0;
}

vector<int> readCardNumber()
{
    string number;
    cout << "Enter a credit card number: ";
    cin >> number;

    vector<int> card_digits;
    for (int i = 0; i < number.size(); ++i) {
        card_digits.push_back(number[i] - '0');
    }
    return card_digits;
}

bool isValid(vector<int> number)
{
    if (((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0) && 
        prefixMatched(number) && 
        13 <= getSize(number) && getSize(number) <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;
    for (int i = number.size() - 2; i >= 0; i -= 2)
    {
        int digit = number[i] * 2;
        sum += getDigit(digit);
    }
    return sum;
}

int sumOfOddPlace(vector<int> number)
{
    int sum = 0;
    for (int i = number.size() - 1; i >= 0; i -= 2)
    {
        sum += number[i];
    }
    return sum;
}

int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

int getSize(vector<int> number)
{
    return number.size();
}

bool prefixMatched(vector<int> number)
{
    if ((getPrefix(number, 1)) == 4 || 
        (getPrefix(number, 1)) == 5 || 
        (getPrefix(number, 2)) == 37 || 
        (getPrefix(number, 1)) == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getPrefix(vector<int> number, int k)
{
    if (k > number.size()) {
        k = number.size();
    }
    
    int k_prefix = 0;
    for (int i = 0; i < k; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }
    return k_prefix;
}