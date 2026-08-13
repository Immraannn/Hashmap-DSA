class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;

        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.length(); right++)
        {
            char ch = s[right];

            // If character was already seen
            if (mp.find(ch) != mp.end())
            {
                left = max(left, mp[ch] + 1);
            }

            // Store latest index of character
            mp[ch] = right;

            // Current window length
            int length = right - left + 1;

            longest = max(longest, length);
        }

        return longest;
    }
};
