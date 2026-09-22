class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> frequency;
        int maxFrequency = 0;
        int longest = 0;

            int left = 0;
            int right = 0;
            while(right < s.size())
            {   
                frequency[s[right]]++;
                maxFrequency = max(maxFrequency, frequency[s[right]]);
                
                int replacements = (right - left + 1) - maxFrequency;
                if(replacements > k)
                {
                    frequency[s[left]]--;
                    left++;
                }
                
                longest = max(longest, right - left + 1);
                right++;
            }
        return longest;
    }
};
