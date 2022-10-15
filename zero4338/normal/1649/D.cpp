#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e6+5;
int n,c,a[maxn];
bool check(int l,int r)
{
	if(a[n]<l)return 0;
	int it=lower_bound(a+1,a+n+1,l)-a;
	return a[it]<=r;
}
bool check(int x){return check(x,x);}
bool vis[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();c=read();
		generate_n(a+1,n,read);
		sort(a+1,a+n+1);n=unique(a+1,a+n+1)-(a+1);
		bool flag=1;
		for(int i=1;i<=c;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=c/a[i];j++)
				if(!vis[j])
				{
					if(check(a[i]*j,a[i]*(j+1)-1))
					{
						if(!check(j)){flag=0;break;}
						vis[j]=1;
					}
				}
			if(!flag)break;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}