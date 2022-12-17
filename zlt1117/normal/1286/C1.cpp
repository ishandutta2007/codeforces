//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
multiset<string>s;
int n;
inline void init()
{

}
inline void input()
{
	cin>>n;
}
inline void query(int l,int r)
{
	cout<<'?'<<' '<<l<<' '<<r<<endl;
	FOR(i,1,(r-l+1)*(r-l+2)/2)
	{
		string ss;
		cin>>ss;
		sort(ss.begin(),ss.end());
		s.insert(ss);
	}
}
inline void solve()
{
	query(1,n);
	if(n==1)cout<<"! "<<*s.begin()<<endl;
	else
	{
		cout<<"? "<<2<<' '<<n<<endl;
		FOR(i,1,n*(n-1)/2)
		{
			string ss;
			cin>>ss;
			sort(ss.begin(),ss.end());
			s.erase(s.find(ss));
		}
		cout<<"! ";
		string last="";
		vector<string>vv;
		for(auto x:s)vv.pb(x);
		FOR(i,0,sz(vv)-1)FOR(j,i+1,sz(vv)-1)if(sz(vv[i])>sz(vv[j]))swap(vv[i],vv[j]);
		for(auto x:vv)
		{
			multiset<char>s1;
			for(auto xx:x)s1.insert(xx);
			for(auto xx:last)s1.erase(s1.find(xx));
			cout<<*s1.begin();
			last=x;
		}
		cout<<endl;
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}