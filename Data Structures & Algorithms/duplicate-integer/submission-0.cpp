class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = nums.size() - 1; j > i; --j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};