#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Function to check whether the array contains duplicate elements
bool containsDuplicate(vector<int>& nums)
{
    unordered_map<int, bool> mp;
    for (int num : nums)
    {
        // If current element already exists,
        // duplicate is found
        if (mp.find(num) != mp.end())
        {
            return true;
        }
        mp[num] = true;
    }
    // No duplicate found
    return false;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    if (containsDuplicate(nums))
        cout << "Duplicate Present";
    else
        cout << "No Duplicate";

    return 0;
}
