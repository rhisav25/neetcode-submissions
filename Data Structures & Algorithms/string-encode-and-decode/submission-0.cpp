class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto str:strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string>res;

        while(i<s.size()){
            int j = i;
            while(s[j]!='#'){
                j = j+1;
            }
            int length = stoi(s.substr(i,j-i));
            i = j+1;
            j = i+length;
            string str = s.substr(i,length);
            res.push_back(str);
            i = j;
        }
        return res;
    }
};
