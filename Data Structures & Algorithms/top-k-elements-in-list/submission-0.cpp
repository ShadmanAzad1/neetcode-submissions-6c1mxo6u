class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& [key, val] : mp) {
            buckets[val].push_back(key);
        }

        for(int i = buckets.size() - 1; i >= 0; i--) {
            for(int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
