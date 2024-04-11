#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e3+5;
int n,k,cnt;
int ans[maxn][maxn];
void link(vector<int>&a,vector<int>&b,int col){for(int &i:a)for(int &j:b)ans[i][j]=col;}
void solve(vector<vector<int>>now)
{
	if(now.size()==1)return;
	vector<vector<int>>np;np.clear();vector<int>tmp;cnt++;
	for(int i=0;i<now.size();i+=k)
	{
		int to=min((int)now.size()-1,i+k-1);
		for(int j=i;j<=to;j++)for(int l=j+1;l<=to;l++)link(now[j],now[l],cnt);
		tmp.clear();
		for(int j=i;j<=to;j++)for(int &l:now[j])tmp.push_back(l);
		np.push_back(tmp);
	}
	solve(np);
	return;
}
int main()
{
	n=read();k=read();
	vector<vector<int>>now;now.resize(n);
	for(int i=0;i<n;i++)now[i].push_back(i+1);
	solve(now);
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)printf("%d ",ans[i][j]);
	return 0;
}