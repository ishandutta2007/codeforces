#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
const int maxn=2e5+5;
int a[maxn],n;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	ll sum=0;
	FOR(i,1,n)sum+=a[i];
	int cnt=0;multiset<int>S;
	FOR(i,1,n)S.insert(a[i]);
	priority_queue<ll>pq;pq.push(sum);cnt=1;
	while(!pq.empty())
	{
		ll x=pq.top();pq.pop();
		if(S.find(x)!=S.end())S.erase(S.find(x));
		else
		{
			pq.push(x/2);
			pq.push((x+1)/2);cnt++;
		}
		if(cnt>=n+1)break;
	}
	if(cnt==n)puts("Yes");
	else puts("No");
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}