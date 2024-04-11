#include<bits/stdc++.h>
typedef long long ll;
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
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		sort(a+1,a+n+1);
		if(a[n]==0){puts("0");continue;}
		ll sum=0;
		for(int i=1;i<n;i++)sum+=a[i];
		printf("%lld\n",1+max(0ll,a[n]-sum-1));
	}
	return 0;
}