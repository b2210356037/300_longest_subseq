#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(res.empty() || nums[i] > res[res.size()-1]){
                res.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(res.begin(), res.end(), nums[i]);
                *it = nums[i];
            }
        }
        return res.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}
