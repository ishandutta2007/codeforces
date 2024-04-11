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
struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x+=0x9e3779b97f4a7c15;
		x=(x^(x>>30))*0xbf58476d1ce4e5b9;
		x=(x^(x>>27))*0x94d049bb133111eb;
		return x^(x>>31);
	}
	size_t operator()(uint64_t x)const
	{
		static const uint64_t FIXED_RANDOM=(unsigned long long)(new int);
		return splitmix64(x+ FIXED_RANDOM);
	}
};
int T;
const int maxn=2e5+5;
int n;
ll ans;
int a[maxn];
unordered_map<int,int,custom_hash>cnt;
int main()
{
	T=read();
	while(T--)
	{
		generate(a+1,a+1+(n=read()),read);
		ll sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		sum*=2;
		if(sum%n){printf("0\n");continue;}
		sum/=n;
		cnt.clear();ans=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt.count(sum-a[i]))ans+=cnt[sum-a[i]];
			cnt[a[i]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}