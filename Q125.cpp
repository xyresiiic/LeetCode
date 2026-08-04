#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) 
        {
         while (left < right && !isalnum(s[left]))
         left++;

         while (left < right && !isalnum(s[right]))
         right--;
         
          if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

int main() 
{
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (solution.isPalindrome(input)) 
    {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } 
    else 
    {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}