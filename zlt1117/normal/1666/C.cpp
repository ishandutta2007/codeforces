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
struct Point
{
	int x,y;
	inline bool operator < (const Point &b)const{return x==b.x?y<b.y:x<b.x;}
}a[5];
struct node
{
	int a,b,c,d;
};
vector<node>answer;
inline void input()
{
	FOR(i,1,3)a[i].x=gi(),a[i].y=gi();
	sort(a+1,a+4);
}
inline void solve()
{
	answer.pb({a[1].x,a[1].y,a[2].x,a[1].y});
	answer.pb({a[2].x,a[1].y,a[2].x,a[2].y});
	int t=0;bool flg=0;
	if(a[3].y>=min(a[1].y,a[2].y)&&a[3].y<=max(a[1].y,a[2].y))answer.pb({a[2].x,a[3].y,a[3].x,a[3].y}),flg=1;
	else if(a[3].y>max(a[1].y,a[2].y))t=max(a[1].y,a[2].y);
	else t=min(a[1].y,a[2].y);
	if(!flg)
	{
		answer.pb({a[2].x,t,a[3].x,t});
		answer.pb({a[3].x,t,a[3].x,a[3].y});
	}
	printf("%d\n",sz(answer));
	for(auto x:answer)printf("%d %d %d %d\n",x.a,x.b,x.c,x.d);
}
int main()
{
	input();
	solve();
	return 0;
}