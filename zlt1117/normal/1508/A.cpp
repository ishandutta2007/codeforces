//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
string a,b,c;
int n;
inline void init()
{

}
inline void input()
{
	cin>>n;
	cin>>a>>b>>c;
}
int now[4];
inline int count(string &s)
{
	int cnt=0;
	FOR(i,0,sz(s)-1)cnt+=s[i]=='0';
	return cnt;
}
inline void solve()
{
	now[0]=now[1]=now[2]=0;
	now[0]=count(a);now[1]=count(b),now[2]=count(c);
	int res=0;
	FOR(i,0,2)res+=now[i]<=n;
	FOR(i,0,2)cerr<<now[i]<<endl;
	if(res>=2)
	{///color 1
		if(now[0]>n)swap(a,c),swap(now[0],now[2]);
		if(now[1]>n)swap(b,c),swap(now[1],now[2]);
		if(now[0]>now[1])swap(a,b),swap(now[0],now[1]);
		int cnt=0;
		vector<int>vec;
		FOR(i,0,sz(b)-1)
		{
			if(b[i]=='1')cnt++;
			else vec.pb(cnt);
		}
		cnt=0;
		int pos=0;
		while(pos<sz(vec)&&vec[pos]==cnt)cout<<'0',pos++;
		FOR(i,0,sz(a)-1)
		{
			cnt+=a[i]=='1';
			cout<<a[i];
			while(pos<sz(vec)&&vec[pos]==cnt)cout<<'0',pos++;
		}
		cout<<endl;
	}
	else
	{
		if(now[0]<=n)swap(a,c),swap(now[0],now[2]);
		if(now[1]<=n)swap(b,c),swap(now[1],now[2]);
		if(now[0]<now[1])swap(a,b),swap(now[0],now[1]);
		int cnt=0;
		vector<int>vec;
		FOR(i,0,sz(b)-1)
		{
			if(b[i]=='0')cnt++;
			else vec.pb(cnt);
		}
		cnt=0;
		int pos=0;
		while(pos<sz(vec)&&vec[pos]==cnt)cout<<'1',pos++;
		FOR(i,0,sz(a)-1)
		{
			cnt+=a[i]=='0';
			cout<<a[i];
			while(pos<sz(vec)&&vec[pos]==cnt)cout<<'1',pos++;
		}
		cout<<endl;
	}
}
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}