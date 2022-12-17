#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e3+5;
int a[maxn],n;
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
vector<pair<int,int> >answers;
bool ok[maxn][maxn];
int p[maxn];
inline void solve()
{
	vector<int>pos;
	FOR(i,1,n)pos.pb(i);
	sort(pos.begin(),pos.end(),[&](int i,int j){return a[i]==a[j]?i<j:a[i]<a[j];});
	int cnt=0;
	FOR(i,1,n)FOR(j,i+1,n)ok[i][j]=a[i]>a[j];
	for(int i:pos)
	{
		vector<pair<int,int> >v;
		FOR(j,i+1,n)if(ok[i][j])v.pb({a[j],j});
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		for(auto x:v)answers.pb({i,x.second}),swap(a[i],a[x.second]);
	}
	printf("%d\n",sz(answers));
	for(auto x:answers)printf("%d %d\n",x.first,x.second);
	FOR(i,1,n-1)assert(a[i]<=a[i+1]);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	input();
	solve();
	return 0;
}
/*
5
3 4 3 1 2
1 5
1 4
3 5
3 4
2 5
2 4
2 3
*/