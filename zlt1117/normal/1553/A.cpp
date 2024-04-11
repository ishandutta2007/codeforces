#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define PII pair<int,int>
#define sz(x) (int)(x.size())
#define mk make_pair
#define pb push_back
#define iter set<int>::iterator
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
int n;
inline void input()
{
	n=gi();
}
inline void solve()
{
	printf("%d\n",(n+1)/10);
}
int main()
{
	int T=gi();
	while(T--)
	{
		input();
		solve();
	}
	return 0;
}