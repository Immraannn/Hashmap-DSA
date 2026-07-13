#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count the number of subarrays
// whose sum is equal to k
int subarraySum(vector<int>& nums, int k)
{
    // HashMap:
    // Key   -> Prefix Sum
    // Value -> Frequency of that Prefix Sum
    unordered_map<int, int> mp;

    // Base case:
    // Prefix sum 0 has occurred once before starting.
    // This helps in counting subarrays that start from index 0.
    mp[0] = 1;

    int prefixSum = 0; // Running prefix sum
    int count = 0;     // Stores answer

    // Traverse the array
    for (int num : nums)
    {
        // Update current prefix sum
        prefixSum += num;

        // We need a previous prefix sum such that:
        // Current Prefix - Previous Prefix = k
        int need = prefixSum - k;

        // If the required prefix sum exists,
        // then one or more valid subarrays are found.
        if (mp.find(need) != mp.end())
        {
            count += mp[need];
        }

        // Store/update the current prefix sum frequency
        mp[prefixSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Number of Subarrays = "
         << subarraySum(nums, k);

    return 0;
}
