#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the most frequent element
int mostFrequentElement(vector<int>& arr)
{
    // HashMap:
    // Key   -> Element
    // Value -> Frequency
    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    int maxFreq = 0;
    int ans = -1;

    // Traverse the HashMap
    for (auto it : freq)
    {
        // Update answer if a higher frequency is found
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            ans = it.first;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,2,1,3,2,1};

    cout << "Most Frequent Element = "
         << mostFrequentElement(arr);

    return 0;
}
//output
//Most Frequent Element = 1
