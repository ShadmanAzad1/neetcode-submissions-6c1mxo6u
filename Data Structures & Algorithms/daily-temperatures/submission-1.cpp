class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we want to save the index of the greater element
        vector<int> result(temperatures.size());
        stack<int> index;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while (!index.empty() && temperatures[i] > temperatures[index.top()])
            {
                result[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return result;
    }
};
