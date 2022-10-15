#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e5+5;
int n;
queue<ll>q;
map<ll,int>cnt;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		ll sum=0;
		cnt.clear();
		for(int i=1;i<=n;i++){ll a=read();cnt[a]++;sum+=a;}
		while(!q.empty())q.pop();
		q.push(sum);
		int T=2*n+100;
		while(!q.empty()&&T--)
		{
			ll x=q.front();q.pop();
			if(cnt.count(x))
			{
				cnt[x]--;
				if(!cnt[x])cnt.erase(x);
				continue;
			}
			q.push((x+1)/2);
			q.push(x/2);
			if(x/2<cnt.begin()->first)break;
		}
		if(q.empty())puts("YES");
		else puts("NO");
	}
}