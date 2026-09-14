class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;
        unordered_set<char> seen;

        for(int i = 0; i < s.size(); i++)
        {
            while (seen.count(s[i])) 
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            longest = max(i - left + 1, longest);
        }
        return longest;
    }
};
