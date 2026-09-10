class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we want to save the index of the greater element
        vector<int> result(temperatures.size());
        stack<int> index;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while (!index.empty() && temperatures[i] > temperatures[index.top()]) /* only runs
             when the current iteration is higher than what we have at the top of the stack*/
            {
                result[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return result;
    }
};
