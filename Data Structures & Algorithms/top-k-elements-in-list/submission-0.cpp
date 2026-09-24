using std::unordered_map;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // build the frequency map 
        unordered_map<int, int> freq_map;
        for (int i=0; i<nums.size(); i++) {
            freq_map[nums[i]]++;
        }

        // max freq = size of nums:
        vector<vector<int>> spots(nums.size()+1);
        vector<int> results;

        for (const auto& [num, count] : freq_map) {
            spots[count].push_back(num);
        }

        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int num : spots[freq]) {
                results.push_back(num);

                if (results.size() == k)
                    return results;
            }
        }
    }
};
