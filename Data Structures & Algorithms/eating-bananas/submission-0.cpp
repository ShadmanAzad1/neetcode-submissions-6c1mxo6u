class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        auto temp = std::max_element(piles.begin(), piles.end());
        int max = *temp;
        int res = max;

        while(min <= max)
        {
            int mid = min + (max - min) / 2;

            int time = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                time += (piles[i] + mid - 1) / mid;
            }
            if(time <= h)
            {
                res = mid;
                max = mid-1;
            }

            else
            {
                min = mid + 1;
            }
        }

        return res;
    }
};
