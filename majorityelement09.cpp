// Intuition
// Count the frequency of every element.
// The element whose frequency becomes greater than n/2 is the answer.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;

        if (freq[num] > nums.size() / 2)
        {
            return num;
        }
    }

    return -1;
}
