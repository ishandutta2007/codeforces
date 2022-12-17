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
const int maxn=1<<18;
int n,a[maxn],k,v[maxn],temp[maxn];
char s[maxn];
inline void init()
{

}
inline void input()
{
	k=gi();n=1<<k;
	scanf("%s",s);
	FOR(i,0,n-1)a[i]=i,v[i]=s[i]-'a';///the rank start from i
	sort(a,a+n,[&](int x,int y){return s[x]==s[y]?x<y:s[x]<s[y];});
}
inline void solve()
{
	FOR(l,1,k)
	{
		int t=1<<(l-1);
		sort(a,a+n,[&](int x,int y){return v[x]==v[y]?v[x^t]<v[y^t]:v[x]<v[y];});
		int cnt=0;
		FOR(i,0,n-1)
		{
			if(!i||(v[a[i]]!=v[a[i-1]]||v[a[i]^t]!=v[a[i-1]^t]))
			{
				++cnt;
				temp[a[i]]=cnt;
			}
			else temp[a[i]]=cnt;
		}
		FOR(i,0,n-1)v[i]=temp[i];
	}
	FOR(i,0,n-1)printf("%c",s[i^a[0]]);
	printf("\n");
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