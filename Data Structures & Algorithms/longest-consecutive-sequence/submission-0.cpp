class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int longest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            seen.insert(nums[i]);
        }

        for (int num : seen) {

    // Check if num is the START of a sequence
            if (seen.count(num - 1) == 0) {  // num-1 not in set
                int current = num;
                int length = 1;
    
                while (seen.count(current + 1)) {
                    length++;
                    current++;
                }
        
                longest = max(longest, length);
            }
        }

    return longest;
    }
};
