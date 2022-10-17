#include<bits/stdc++.h>
#define N 110
using namespace std;

int n,dp[N];
string str;

int main()
{
    memset(dp,-1,sizeof(dp));
    int i,j;
    cin>>n>>str;
    if(n==1)
    {
	puts("1");
	return 0;
    }
    for(i=n/2;i>=2;i--)
    {
	if(str.substr(0,i)==str.substr(i,i)) break;
    }
    cout<<n-i+1;
}