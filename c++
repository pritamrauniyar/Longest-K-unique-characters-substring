class Solution{
    public:
    int longestKSubstr(string s, int k) {
     unordered_map<char,int>m;
     int i=0,j=0,ans=0;
     while (j<s.length())
     {
            m[s[j]]++;
         if (m.size()<k)
         j++;
         else if(m.size()==k ){
            ans=max(ans,j-i+1);
            j++;
         }
         else if (m.size()>k){
             while(m.size()>k){
                 m[s[i]]--;
                 if(m[s[i]]==0)
                     m.erase(s[i]);
                 i++;
             }
              j++;
         }
     }
     if(ans<=0)
     return -1;
     else
     return ans;
    }
};
