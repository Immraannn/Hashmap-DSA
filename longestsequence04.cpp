class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int longest=0;
        for (int num : nums)
    {
        mp[num] = true;
    }
        for(auto it:mp){
            int num=it.first;
            if(mp.find(num-1)==mp.end() ){
              int curr=num;
              int length=1;
             // mp[num]=false;
              while(mp.find(curr+1)!=mp.end()){
                
                curr++;
                length++;
              }
            

              longest=max(longest,length);
            }
           
           
        }
        return longest;

        
    }
};
