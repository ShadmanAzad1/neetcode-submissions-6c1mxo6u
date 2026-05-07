class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,  vector<string>> anagramMap;

        for(string s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());

            anagramMap[sorted].push_back(s);
        }

        vector<vector<string>> result;
        for(auto const&[key, group] : anagramMap) {
            result.push_back(group);
        }

        return result;
    }
};
