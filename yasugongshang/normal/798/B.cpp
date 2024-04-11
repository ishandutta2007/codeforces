#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
string s[51],ts[51];
int l,r,len,sum,n,ans=1e9;
inline void doit(int x)
{
	For(i,1,n)	s[i]=ts[i];
	int sum=0;
	string bz;
	bz=s[x];
	For(i,1,n)
	{
		if(x==i)	continue;
		int tot=0;
		while(s[i]!=bz)
		{
			string tmp;
			For(j,1,len-1)	tmp+=s[i][j];
			tmp+=s[i][0];
			tot++;
			sum++;
			if(tot>len){puts("-1");exit(0);}
			s[i]=tmp;
		}
	}
	ans=min(ans,sum);
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	For(i,1,n)
		cin>>ts[i];
	len=ts[1].length();
	For(i,2,n)	if(ts[i].length()!=len)	{puts("-1");return 0;}	
	For(i,1,n)	doit(i);
	printf("%d",ans);
}