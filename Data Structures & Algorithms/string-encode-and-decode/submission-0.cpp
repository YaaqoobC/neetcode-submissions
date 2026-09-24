class Solution {
public:
    string encode(vector<string>& strs) {
        // Packet Structure => num_chars#<str>
        string result;
        for (string str : strs) {
            result += to_string(str.size());
            result += '#';
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the '#'
            while (s[j] != '#') {
                j++;
            }

            // Characters from i -> j are the length
            int length = stoi(s.substr(i, j - i));

            // The actual string starts after '#'
            string str = s.substr(j + 1, length);
            result.push_back(str);

            // Move to the next encoded string
            i = j + 1 + length;
        }

        return result;
    }
};
