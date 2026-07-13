#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to group all anagrams together
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    // HashMap:
    // Key   -> Sorted version of a word
    // Value -> All original words having the same sorted form
    unordered_map<string, vector<string>> mp;

    // Traverse each word in the input array
    for (string word : strs)
    {
        // Make a copy because we don't want to modify
        // the original word stored in the array
        string sortedWord = word;

        // Sort the copied word
        // Example:
        // "tea" -> "aet"
        // "eat" -> "aet"
        // "ate" -> "aet"
        sort(sortedWord.begin(), sortedWord.end());

        // Insert the original word into the vector
        // corresponding to its sorted form.
        //
        // If the key doesn't exist,
        // unordered_map automatically creates an empty vector.
        //
        // Example:
        // mp["aet"].push_back("eat");
        // mp["aet"].push_back("tea");
        // mp["aet"].push_back("ate");
        mp[sortedWord].push_back(word);
    }

    // This vector will store the final grouped anagrams
    vector<vector<string>> ans;

    // Traverse every entry in the HashMap
    for (auto it : mp)
    {
        // it.first  -> Sorted string (Key)
        // it.second -> Vector of original strings (Value)

        // Store the grouped anagrams in the answer
        ans.push_back(it.second);
    }

    // Return the final grouped anagrams
    return ans;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    // Function call
    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";

    // Print every group
    for (auto group : ans)
    {
        cout << "[ ";

        // Print every word inside the current group
        for (string word : group)
        {
            cout << word << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
