#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Function to return the k most frequent elements
vector<int> topKFrequent(vector<int>& nums, int k)
{
    // HashMap:
    // Key   -> Element
    // Value -> Frequency
    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int num : nums)
    {
        freq[num]++;
    }

    // Min Heap
    // pair.first  -> Frequency
    // pair.second -> Element
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > minHeap;

    // Traverse frequency map
    for (auto it : freq)
    {
        // Insert (frequency, element)
        minHeap.push({it.second, it.first});

        // Keep only k elements in heap
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> ans;

    // Remaining heap contains top k frequent elements
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top K Frequent Elements : ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
