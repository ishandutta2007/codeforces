#include<bits/stdc++.h>
using namespace std;

const int MAXN=60;
int kmps[MAXN],kmpt[MAXN];//the max length in 0~i that prefix==suffix
//indicate the place to go when mismatching
void FailureFunction(const string& pattern,int fail[],int nxt[][26]){
   fail[0]=0;
   for(int i=1;i<pattern.size();i++){
      fail[i]=fail[i-1];
      while(fail[i]>0&&pattern[fail[i]]!=pattern[i])
         fail[i]=fail[fail[i]-1];
      if(pattern[fail[i]]==pattern[i]) fail[i]++;
   }
   for(char c='a';c<='z';c++)
   		for(int i=0;i<=pattern.size();i++){
   			nxt[i][c-'a']=i;
   			while(pattern[nxt[i][c-'a']]!=c&&nxt[i][c-'a']>0)
   				nxt[i][c-'a']=fail[nxt[i][c-'a']-1];
   			if(pattern[nxt[i][c-'a']]==c)	nxt[i][c-'a']++;
   		}
}

string text,s,t;
int fails[MAXN],failt[MAXN];
int nxt_s[MAXN][26],nxt_t[MAXN][26];
int dp[1001][MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>text>>s>>t;
	for(int i=0;i<=text.size();i++)
		for(int j=0;j<=s.size();j++)
			for(int k=0;k<=t.size();k++)
				dp[i][j][k]=-1e9;
	dp[0][0][0]=0;
	FailureFunction(s,fails,nxt_s);
	FailureFunction(t,failt,nxt_t);
	for(int i=1;i<=text.size();i++)
		for(int j=0;j<=s.size();j++)
			for(int k=0;k<=t.size();k++)
				for(char c='a';c<='z';c++)
					if(text[i-1]==c||text[i-1]=='*'){
						int nexts=nxt_s[j][c-'a'],nextt=nxt_t[k][c-'a'];
						dp[i][nexts][nextt]=max(dp[i][nexts][nextt],dp[i-1][j][k]+(nexts==s.size())-(nextt==t.size()));
					}
	int ans=-1e9;
	for(int i=0;i<=s.size();i++)
		for(int j=0;j<=t.size();j++)
			ans=max(ans,dp[text.size()][i][j]);
	cout<<ans<<endl;
}