#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;   // negative numbers not palindrome

        int original = x;
        long reversed = 0;

        while (x > 0) 
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return original == reversed;
    }
};

int main() 
{
    Solution solution;
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (solution.isPalindrome(number)) 
    {
        cout << number << " is a palindrome." << endl;
    } 
    else 
    {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}