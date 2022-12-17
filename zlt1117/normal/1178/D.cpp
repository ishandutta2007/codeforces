//#pragma GCC optimize("Ofast")
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
inline bool prime(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)return false;
	}
	return true;
}
const int maxn=1005;
int ind[maxn],n,ans;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)ind[i]=2,ans+=2;
}
inline void solve()
{
	int p=n;
	while(!prime(ans/2))
	{
		ind[p]++;
		ind[p-1]++;
		ans+=2;p-=2;
	}
	set<pair<int,int>>S;
	FOR(i,1,n)S.insert({ind[i],i});
	vector<pair<int,int>>answer;
	while(!S.empty())
	{
		int x=(*S.begin()).second;
		S.erase(S.begin());
		vector<int>v;
		FOR(i,1,ind[x])
		{
			auto it=--S.end();
			answer.pb({x,(*it).second});
			v.pb((*it).second);
			ind[(*it).second]--;S.erase(it);
		}
		ind[x]=0;
		for(int x:v)S.insert({ind[x],x});
	}
	printf("%d\n",sz(answer));
	for(auto x:answer)printf("%d %d\n",x.first,x.second);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}