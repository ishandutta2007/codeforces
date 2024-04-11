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
const int maxn=1e5+5;
int n;
struct point{int id,a,b;}p[maxn];
int num[maxn],cnt;
bool ans[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)p[i].id=i,p[i].a=read();
		cnt=0;
		for(int i=1;i<=n;i++)num[++cnt]=p[i].b=read();
		sort(num+1,num+cnt+1);
		for(int i=1;i<=n;i++)p[i].b=lower_bound(num+1,num+cnt+1,p[i].b)-num;
		sort(p+1,p+n+1,[](point &i,point &j){return i.a<j.a;});
		int lst=0,mx=0;
		for(int i=1;i<n;i++)
		{
			mx=max(mx,p[i].b);
			if(mx==i)lst=i;
		}
		for(int i=1;i<=lst;i++)ans[p[i].id]=0;
		for(int i=lst+1;i<=n;i++)ans[p[i].id]=1;
		for(int i=1;i<=n;i++)printf("%d",ans[i]);putchar('\n');
	}
	return 0;
}