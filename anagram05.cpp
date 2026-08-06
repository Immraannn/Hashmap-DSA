#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> mp;
    for (string word : strs)
    {
        string sortedWord = word;
        // "ate" -> "aet"
        sort(sortedWord.begin(), sortedWord.end());
        mp[sortedWord].push_back(word);
    }
    vector<vector<string>> ans;
    for (auto it : mp)
    {
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
