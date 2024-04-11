#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n,q,a[maxn];
int tol[21][maxn],tor[21][maxn];
int stl[21][21][maxn],str[21][21][maxn],Lg2[maxn];
void build(int d)
{
	for(int i=1;i<n;i++)stl[d][0][i]=tol[d][i],str[d][0][i]=tor[d][i];
	for(int i=1;(1<<i)<n;i++)
		for(int j=1;j+(1<<i)-1<n;j++)
		{
			stl[d][i][j]=min(stl[d][i-1][j],stl[d][i-1][j+(1<<(i-1))]);
			str[d][i][j]=max(str[d][i-1][j],str[d][i-1][j+(1<<(i-1))]);
		}
}
pair<int,int>query(int d,int l,int r)
{
	r--;
	if(l>r)return {l,l};
	int k=Lg2[r-l+1];
	return {min(stl[d][k][l],stl[d][k][r-(1<<k)+1]),max(str[d][k][l],str[d][k][r-(1<<k)+1])};
}
int main()
{
	n=read();q=read();
	generate_n(a+1,n,read);
	for(int i=1;i<n;i++)tol[0][i]=min(a[i],a[i+1]),tor[0][i]=max(a[i],a[i+1]);
	for(int i=2;i<=n;i++)Lg2[i]=Lg2[i>>1]+1;
	build(0);
	for(int i=1;i<21;i++)
	{
		for(int j=1;j<n;j++)tie(tol[i][j],tor[i][j])=query(i-1,tol[i-1][j],tor[i-1][j]);
		build(i);
	}
	while(q--)
	{
		int l=read(),r=read();
		if(l==1&&r==n){puts("0");continue;}
		if(l==r)
		{
			if(n==1)puts("0");
			else puts("-1");
			continue;
		}
		int ret=0;
		for(int i=20;i>=0;i--)
		{
			auto to=query(i,l,r);
			if(to.first!=1||to.second!=n)
			{
				ret+=1<<i;
				l=to.first;r=to.second;
			}
		}
		tie(l,r)=query(0,l,r);
		ret++;
		if(l!=1||r!=n)puts("-1");
		else printf("%d\n",ret);
	}
	return 0;
}