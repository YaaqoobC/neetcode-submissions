using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // same characters, appearing the same # of times
        if (s == t)
            return true;
        
        if (s.length() != t.length())
            return false;

        // At this point they are the same lenght:
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for (int i=0; i < s.length(); i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        
        return s_map == t_map;
    }
};
