using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i=0; i < nums.size(); i++) {
            nums_map[nums[i]] = i; // duplicate will override to the last most index.
        }

        for (int i=0; i < nums.size(); i++) {
            int num_want = target - nums[i];
            if (nums_map.contains(num_want) && i != nums_map[num_want]) {
                return {i, nums_map[num_want]};
            }
        }
    }
};
