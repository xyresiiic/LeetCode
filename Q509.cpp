#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) 
    {
     if (n == 0) 
     return 0;
     if (n == 1) 
     return 1;
     return fib(n - 1) + fib(n - 2);
        
    }
};

int main() 
{
    Solution solution;
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) 
    {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = solution.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}