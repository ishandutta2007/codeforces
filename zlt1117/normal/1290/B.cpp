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
const int maxn=2e5+5;
int sum[maxn][26];
char s[maxn];
int n;
inline void init()
{
	
}
inline void input()
{
	scanf("%s",s+1);n=strlen(s+1);
	FOR(i,1,n)
	{
		sum[i][s[i]-'a']++;
		FOR(j,0,25)sum[i][j]+=sum[i-1][j];
	}
}
inline void solve()
{
	int q=gi();
	FOR(i,1,q)
	{
		int l=gi(),r=gi();
		if(l==r){puts("Yes");continue;}
		int cnt=0;vector<int>v;
		FOR(j,0,25)if(sum[r][j]-sum[l-1][j]!=0)v.pb(j),cnt++;
		if(cnt>=3){puts("Yes");continue;}
		else if(cnt==1){puts("No");continue;}
		if(s[l]!=s[r]){puts("Yes");continue;}
		puts("No");
	}
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