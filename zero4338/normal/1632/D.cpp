#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
mt19937 rnd(0);
int Rand(int l,int r){uniform_int_distribution<>gen(l,r);return gen(rnd);}
const int maxn=2e5+5;
int n,a[maxn];
int ans;
int st[21][maxn];
void prework()
{
	for(int i=1;i<=n;i++)st[0][i]=a[i];
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int query(int l,int r)
{
	int k=log2(r-l+1);
	return __gcd(st[k][l],st[k][r-(1<<k)+1]);
}
int main()
{
	generate_n(a+1,n=read(),read);
	prework();
	int pos=1;
	for(int i=1;i<=n;i++)
	{
		while(i-pos+1>query(pos,i))pos++;
		if(i-pos+1==query(pos,i))pos=i+1,ans++;
		printf("%d ",ans);
	}
	putchar('\n');
	return 0;
}