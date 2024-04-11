#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
char s[105],t[105];
inline void init()
{
	
}
inline void input()
{
	scanf("%s%s",s+1,t+1);
}
inline void solve()
{
	int lens=strlen(s+1),lent=strlen(t+1);
	reverse(s+1,s+lens+1),reverse(t+1,t+lent+1);
	int j=1;
	multiset<char>S;
	FOR(i,1,lent)S.insert(t[i]);
	FOR(i,1,lens)
	{
		if(s[i]==t[j]&&j<=lent)S.erase(S.find(t[j])),j++;	
		else if(S.count(s[i]))return puts("No"),void();
	} 
	if(j==lent+1)puts("Yes");
	else puts("No");
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}