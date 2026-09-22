using std::unordered_map;

class Solution {
public:
    string getKey(string str) {
        // Build the frequency table:
        int freq[26] = {0};
        for (char c : str) {
            freq[c - 'a']++;
        }

        // Concat the freq table into a string of numbers
        string encoding = "";
        for (int i=0; i<26; i++) {
            char c = static_cast<char>(freq[i]);
            encoding.push_back(c);
        }

        return encoding;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, int> results_index_map;

        for (int i=0; i<strs.size(); i++) {
            // Build the encoding from the string
            string encoded_key = getKey(strs[i]);

            if (results_index_map.contains(encoded_key)) {
                // The anagram has already been added => throw it in the results vector at the index
                int k = results_index_map[encoded_key];
                results[k].push_back(strs[i]);
            } else {
                // The anagram has not been added => throw it in the results vector and record the index
                results_index_map[encoded_key] = results.size();
                results.push_back({strs[i]});
            }   
        }

        return results; 
    }   
};
