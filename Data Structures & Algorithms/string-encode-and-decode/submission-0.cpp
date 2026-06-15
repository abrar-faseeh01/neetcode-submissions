class Solution {
public:

string encode(vector<string>& strs) {
    string ans = "";

    for(int i = 0; i < strs.size(); i++){
        ans += to_string(strs[i].size()) + "#" + strs[i];
    }

    return ans;
}

    vector<string> decode(string s) {
    vector<string> result;

    int i = 0;

    while(i < s.size()) {

        int j = i;

        while(s[j] != '#') {
            j++;
        }

        string lenStr = s.substr(i, j - i);
        int len = stoi(lenStr);

        string word = "";

        for(int k = j + 1; k < j + 1 + len; k++) {
            word += s[k];
        }

        result.push_back(word);

        // Move to next encoded string
        i = j + 1 + len;
    }

    return result;
}
};
