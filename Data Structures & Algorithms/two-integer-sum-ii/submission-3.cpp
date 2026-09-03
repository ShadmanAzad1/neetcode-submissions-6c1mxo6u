class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> index(2);
        index[0] = 0;
        index[1] = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[index[0]] + numbers[index[1]] > target)
            {
                index[1]--;
            }

            else if(numbers[index[0]] + numbers[index[1]] < target)
            {
                index[0]++;
            }
        }

        index[0]++;
        index[1]++;
        return index;
    }
};
