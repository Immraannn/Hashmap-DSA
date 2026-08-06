// A number is happy if:
// Replace the number with the sum of the squares of its digits.
// Repeat the process.
// If you eventually reach 1, the number is happy.
// If the process enters a cycle, the number is not happy.

#include <iostream>
#include <unordered_set>
using namespace std;

// Returns the sum of the squares of digits
int getNext(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> seen;
    while (n != 1)
    {
        // Cycle detected
        if (seen.find(n) != seen.end())
        {
            return false;
        }

        seen.insert(n);

        n = getNext(n);
    }
    return true;
}
