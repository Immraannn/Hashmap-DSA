class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < sorted.size(); i++) {
            // Only assign a new rank to a new value
            if (mp.find(sorted[i]) == mp.end()) {
                mp[sorted[i]] = rank;
                rank++;
            }
        }
        // Replace each element with its rank
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
