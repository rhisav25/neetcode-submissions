class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1,m2;
        int count = 0;
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        int l=0;
        int len = s2.length();
        for(int r=0;r<s2.size();r++){
           m2[s2[r]]++;
           if(r-l>=s1.length()){
            m2[s2[l]]--;
            if(m2[s2[l]]==0){
                m2.erase(s2[l]);
            }
            l++;
           }
           if(m1==m2)return true;
        }
        return false;
          
    }
};
