#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
const int p1=998244353;
const int p2=1e9+7;
const int p3=993244853;
int n,m;
char s[maxn],t[maxn];
int nxt[maxn],f[maxn];
struct hash_table
{
	int mod,ppow[maxn],sum[maxn];
	hash_table(int x){mod=x;}
	void build(char *s)
	{
		int n=strlen(s+1);
		ppow[0]=1;
		for(int i=1;i<=n;i++)ppow[i]=(ll)ppow[i-1]*10%mod;
		for(int i=1;i<=n;i++)sum[i]=((ll)sum[i-1]*10%mod+s[i]-'0')%mod;
	}
	int get(int l,int r){return (sum[r]-(ll)sum[l-1]*ppow[r-l+1]%mod+mod)%mod;}
	int get(int l1,int r1,int l2,int r2){return (get(l1,r1)+get(l2,r2))%mod;}
}ha1(p1),ha2(p2),ha3(p3);
int v1,v2,v3;
bool judge(int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2||r2>n||l1<1)return false;
	return ha1.get(l1,r1,l2,r2)==v1&&ha2.get(l1,r1,l2,r2)==v2&&ha3.get(l1,r1,l2,r2)==v3;
}
int main()
{
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	nxt[1]=m;
	for(int i=2,l=0,r=0;i<=m;i++)
	{
		if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1);
		while(i+nxt[i]<=m&&t[i+nxt[i]]==t[nxt[i]+1])nxt[i]++;
		if(i+nxt[i]-1>r)r=i+nxt[i]-1,l=i;
	}
	for(int i=1,l=0,r=0;i<=n;i++)
	{
		if(i<=r)f[i]=min(nxt[i-l+1],r-i+1);
		while(i+f[i]<=n&&f[i]+1<=m&&s[i+f[i]]==t[f[i]+1])f[i]++;
		if(i+f[i]-1>r)r=i+f[i]-1,l=i;
	}
	ha1.build(s);ha2.build(s);ha3.build(s);
	for(int i=1;i<=m;i++)
	{
		v1=((ll)v1*10+t[i]-'0')%p1;
		v2=((ll)v2*10+t[i]-'0')%p2;
		v3=((ll)v3*10+t[i]-'0')%p3;
	}
	if(m>1)
		for(int i=1;i<=n+3-2*m;i++)
			if(judge(i,i+m-2,i+m-1,i+2*m-3)){printf("%d %d\n%d %d\n",i,i+m-2,i+m-1,i+2*m-3);return 0;}
	for(int i=1;i<=n-m+1;i++)
	{
		if(judge(i,i+m-1,i+m,i+2*m-f[i]-1)){printf("%d %d\n%d %d\n",i,i+m-1,i+m,i+2*m-f[i]-1);return 0;}
		if(judge(i,i+m-1,i+m,i+2*m-f[i]-2)){printf("%d %d\n%d %d\n",i,i+m-1,i+m,i+2*m-f[i]-2);return 0;}
		if(judge(i-m+f[i],i-1,i,i+m-1)){printf("%d %d\n%d %d\n",i-m+f[i],i-1,i,i+m-1);return 0;}
		if(judge(i-m+f[i]+1,i-1,i,i+m-1)){printf("%d %d\n%d %d\n",i-m+f[i]+1,i-1,i,i+m-1);return 0;}
	}
	puts("error");
	return 0;
}