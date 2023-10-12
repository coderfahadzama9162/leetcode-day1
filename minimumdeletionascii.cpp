#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int find(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){

    if(i<0) {

  int sum=0;
        
        for(int index=0;index<=j;index++) sum+=int(word2[index]);
        
         return sum;
    };

    if(j<0) {

     int sum=0;
        
        for(int index=0;index<=i;index++) sum+=int(word1[index]);

         return sum;
    }
     

     if(dp[i][j]!=-1) return dp[i][j];

    if(word1[i]==word2[j])  return dp[i][j]= find(i-1,j-1,word1,word2,dp);

    else return dp[i][j]= min(int(word2[j])+find(i,j-1,word1,word2,dp),int(word1[i])+find(i-1,j,word1,word2,dp));


}
    int minimumDeleteSum(string word1, string word2) {
         int n=word1.size();
         int m=word2.size();
  vector<vector<int>>dp(n,vector<int>(m,-1));

  return find(n-1,m-1,word1,word2,dp);

    }
};
int main(){
     string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    Solution* sol = new Solution();

    cout << sol->minimumDeleteSum(s1, s2) << endl;
}