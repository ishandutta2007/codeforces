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
int n,m;
inline int A(int x,int y)
{
	printf("SCAN %d %d\n",x,y);
	fflush(stdout);
	int ret=gi();
	return ret;
}
inline int B(int x,int y)
{
	printf("DIG %d %d\n",x,y);
	fflush(stdout);
	int ret=gi();
	return ret;
}
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi();
}
inline void solve()
{
	int x=0,y=0,va=A(1,1),vb=A(n,1);
	x=(vb+va-2*n+6)/2;
	y=(va-x+4);swap(x,y);
	int tx=x/2,ty=y/2;
	int now=A(tx,ty);
	int xy1=(now-x-y)/-2;
	int val=A(tx,1);
	int x12=val-y+2;
	int x2=(x12+x)/2,x1=(x-x12)/2;
	int y12=now-(x2-x1);
	int y2=(y12+y)/2,y1=(y-y12)/2;
	int cnt=0;
	if(B(x1,y1))B(x2,y2);
	else
	{
		B(x1,y2);
		B(x2,y1);
	}
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