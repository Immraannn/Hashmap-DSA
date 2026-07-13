#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to print frequency of each element
void frequencyCount(vector<int>& arr)
{
    unordered_map<int, int> freq;

    // Count frequency
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    // Print frequencies
    for (auto it : freq)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

int main()
{
    vector<int> arr = {1,2,1,3,2,1};

    frequencyCount(arr);

    return 0;
}
