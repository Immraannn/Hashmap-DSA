#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the length of the longest consecutive sequence
int longestConsecutive(vector<int>& nums)
{
    // HashMap stores:
    // Key   -> Array element
    // Value -> true (indicates the element exists)
    unordered_map<int, bool> mp;

    // Insert all elements into the HashMap
    for (int num : nums)
    {
        mp[num] = true;
    }

    // Stores the maximum length of any consecutive sequence
    int longest = 0;

    // Traverse every element in the array
    for (int num : nums)
    {
        // Check whether the current number is the START of a sequence.
        // If (num - 1) does not exist, then num is the first element.
        if (mp.find(num - 1) == mp.end())
        {
            // Start counting the sequence from 'num'
            int current = num;
            int length = 1;

            // Continue while the next consecutive number exists
            while (mp.find(current + 1) != mp.end())
            {
                current++;   // Move to next consecutive number
                length++;    // Increase sequence length
            }

            // Update the maximum sequence length found so far
            longest = max(longest, length);
        }
    }

    // Return the longest consecutive sequence length
    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence Length = "
         << longestConsecutive(nums);

    return 0;
}
