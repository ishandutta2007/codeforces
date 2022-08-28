#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 10005

using namespace std;

char A[SIZE];
bool dp[SIZE][2];
int n;

bool check(int i,int j)
{
	if(i>j) swap(i,j);
	int L=j-i;
	for(int k=0;k<L;k++) if(j+k>=n||A[i+k]!=A[j+k]) return true;
	return false;
}
int main()
{
	scanf("%s",&A);
	n=strlen(A);
	vector <string> ans;
	for(int i=n-1;i>=5;i--)
	{
		if(i+2<=n)
		{
			string s="";
			s+=A[i],s+=A[i+1];
			if(i+2==n) dp[i][0]=true;
			else if(dp[i+2][1]||(dp[i+2][0]&&check(i,i+2))) dp[i][0]=true;
			if(dp[i][0]) ans.push_back(s);
		}
		if(i+3<=n)
		{
			string s="";
			s+=A[i],s+=A[i+1],s+=A[i+2];
			if(i+3==n) dp[i][1]=true;
			else if(dp[i+3][0]||(dp[i+3][1]&&check(i,i+3))) dp[i][1]=true;
			if(dp[i][1]) ans.push_back(s);
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%s\n",ans[i].c_str());
	return 0;
}