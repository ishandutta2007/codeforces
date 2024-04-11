#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
mt19937 rnd((unsigned long long)(new int));
const int maxn=1e5+5;
int n,a[maxn];
int id[maxn],num[maxn];
int main()
{
	generate_n(a+1,n=read(),read);
	int T=100;
	for(int i=1;i<=n;i++)id[i]=i;
	while(T--)
	{
		shuffle(id+1,id+n+1,rnd);
		int d1=0,d2=0;
		for(int i=1;i<=n;i++)
		{
			if(__gcd(d1,a[id[i]])!=d1){d1=__gcd(d1,a[id[i]]);num[id[i]]=1;}
			else {d2=__gcd(d2,a[id[i]]);num[id[i]]=2;}
		}
		if(d1==1&&d2==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++)printf("%d ",num[i]);putchar('\n');return 0;
		}
	}
	puts("NO");
	return 0;
}