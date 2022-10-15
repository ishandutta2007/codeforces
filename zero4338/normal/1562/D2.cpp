#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=3e5+5;
int n,q;
char s[maxn];int sum[maxn];
vector<int>v[maxn<<2];
int mx[25][maxn],mi[25][maxn];
int val(int i){return sum[i]+sum[i-1];}
void prework()
{
	for(int i=1;i<=n;i++)mx[0][i]=mi[0][i]=i;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<(j-1))-1<=n;i++)
		{
			if(val(mx[j-1][i])>val(mx[j-1][i+(1<<(j-1))]))mx[j][i]=mx[j-1][i];
			else mx[j][i]=mx[j-1][i+(1<<(j-1))];
	  		if(val(mi[j-1][i])<val(mi[j-1][i+(1<<(j-1))]))mi[j][i]=mi[j-1][i];
			else mi[j][i]=mi[j-1][i+(1<<(j-1))];
	  	}
}
int querymx(int l,int r)
{
	int k=log2(r-l+1);
	if(val(mx[k][l])>val(mx[k][r-(1<<k)+1]))return mx[k][l];
	else return mx[k][r-(1<<k)+1];
}
int querymi(int l,int r)
{
	int k=log2(r-l+1);
	if(val(mi[k][l])>val(mi[k][r-(1<<k)+1]))return mi[k][l];
	else return mi[k][r-(1<<k)+1];
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();q=read();scanf("%s",s+1);
		for(int i=0;i<=n*4;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int now=0;
			if(s[i]=='+')
			{
				if(i&1)sum[i]=sum[i-1]+1;
				else sum[i]=sum[i-1]-1;
			}
			else
			{
				if(i&1)sum[i]=sum[i-1]-1;
				else sum[i]=sum[i-1]+1;
			}
		}
		prework();
		for(int i=1;i<=n;i++)v[sum[i]+sum[i-1]+2*n].push_back(i);
		while(q--)
		{
			int l=read(),r=read();
			if(sum[r]-sum[l-1]==0)printf("0\n");
			else
			{
				auto it=lower_bound(v[sum[r]+sum[l-1]+2*n].begin(),v[sum[r]+sum[l-1]+2*n].end(),l);
				if(it!=v[sum[r]+sum[l-1]+2*n].end()&&*it<=r)printf("1\n%d\n",*it);
				else
				{
					int np=querymi(l,r);
					int now=val(np)+sum[l-1]-sum[r]+2*n;
					bool flag=0;
					if(now>=0&&now<=4*n)
					{
						auto it=lower_bound(v[now].begin(),v[now].end(),l);
						if(it!=v[now].end()&&*it<np){flag=1;printf("2\n%d %d\n",*it,np);}
					}
					now=val(np)+sum[r]-sum[l-1]+2*n;
					if(flag)continue;
					if(now>=0&&now<=4*n)
					{
						auto it=lower_bound(v[now].begin(),v[now].end(),np+1);
						if(it!=v[now].end()&&*it<=r){flag=1;printf("2\n%d %d\n",np,*it);}
					}
					np=querymx(l,r);
					if(flag)continue;
					if(now>=0&&now<=4*n)
					{
						auto it=lower_bound(v[now].begin(),v[now].end(),l);
						if(it!=v[now].end()&&*it<np){flag=1;printf("2\n%d %d\n",*it,np);}
					}
					now=val(np)+sum[r]-sum[l-1]+2*n;
					if(flag)continue;
					if(now>=0&&now<=4*n)
					{
						auto it=lower_bound(v[now].begin(),v[now].end(),np+1);
						if(it!=v[now].end()&&*it<=r){flag=1;printf("2\n%d %d\n",np,*it);}
					}
				}
			}
		}
	}
	return 0;
}