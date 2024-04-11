#include<bits/stdc++.h>
#define maxc 26
#define maxn 550
using namespace std;

int n;
char s[maxn];

int f[maxn][maxn],g[maxn][maxn];

int calcf(int,int); 

int calcg(int l,int r)	{
	if (l>=r)	return 0;
	if (~g[l][r])	return g[l][r];
	g[l][r]=r-l-1;
	for (int i=l+1;i<r;++i)
		if (s[i]==s[l])
			g[l][r]=min(g[l][r],calcf(l+1,i-1)+calcg(i,r));
//	cout<<"calcg:"<<l<<" "<<r<<" "<<g[l][r]<<endl;
	return g[l][r];
}

int calcf(int l,int r)	{
	if (l>r)	return 0;
	if (~f[l][r])	return f[l][r];
	if (l==r)	return f[l][r]=1;
	f[l][r]=r-l+1;
	
	vector<int> pos[maxc];
	for (int i=l;i<=r;++i)	
		pos[s[i]-'a'].push_back(i);
	for (int c=0;c<maxc;++c)	{
		if (!pos[c].size())	continue;
		for (int i=0;i<pos[c].size();++i)	{
			int t=calcf(l,pos[c][i]-1);
			f[l][r]=min(f[l][r],calcg(pos[c][i],r+1)+t+1);
		}
	}
//	cout<<"calcf:"<<l<<" "<<r<<" "<<f[l][r]<<endl;
	return f[l][r];
}

int main()	{
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	scanf("%d%s",&n,s+1);
	printf("%d\n",calcf(1,n));
	return 0;
}