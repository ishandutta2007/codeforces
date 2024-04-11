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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2005;
int n;
vector<pair<int,int>>answers;
inline vector<int> query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	vector<int>ret(n);
	FOR(i,0,n-1)ret[i]=gi();
	return ret;
}
inline void answer(vector<pair<int,int>>&ans)
{
	assert((int)(ans.size())==n-1);
	puts("!");
	for(auto x:answers)printf("%d %d\n",x.first,x.second);
	fflush(stdout);
}
inline void init()
{

}
inline void input()
{
	n=gi();
}
int d[maxn];
inline void solve()
{
	vector<int>now=query(1);
	FOR(i,1,n)d[i]=now[i-1];
	int cnt1=0,cnt2=0;
	vector<int>v1,v2;
	FOR(i,1,n){if(d[i]%2==0)cnt1++,v1.pb(i);else cnt2++,v2.pb(i);}
	if(sz(v1)>sz(v2))swap(v1,v2);
	for(int x:v1)
	{
		vector<int>temp;
		if(x==1)temp=now;
		else temp=query(x);
		FOR(i,0,n-1)if(temp[i]==1)answers.pb({x,i+1});
	}
	answer(answers);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}