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

| i | arr[i] | Operation   | `freq` after operation |
| - | ------ | ----------- | ---------------------- |
| 0 | 1      | `freq[1]++` | `{1:1}`                |
| 1 | 2      | `freq[2]++` | `{1:1, 2:1}`           |
| 2 | 1      | `freq[1]++` | `{1:2, 2:1}`           |
| 3 | 3      | `freq[3]++` | `{1:2, 2:1, 3:1}`      |
| 4 | 2      | `freq[2]++` | `{1:2, 2:2, 3:1}`      |
| 5 | 1      | `freq[1]++` | `{1:3, 2:2, 3:1}`      |

