//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
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
ll T,x,y,c[7],now[7];
int main()
{
	T=gi();
	while(T--)
	{
		y=gi(),x=gi();
		FOR(i,1,6)now[i]=c[i]=gi();
		FOR(i,1,6)
		{
			now[1]=min(now[1],c[2]+c[6]);
			now[2]=min(now[2],c[3]+c[1]);
			now[3]=min(now[3],c[4]+c[2]);
			now[4]=min(now[4],c[5]+c[3]);
			now[5]=min(now[5],c[6]+c[4]);
			now[6]=min(now[6],c[1]+c[5]);
			memcpy(c,now,sizeof(c));
		}
		ll ans=1e18;
		if(x>=0&&y>=0)
		{
			ans=min(ans,c[1]*(min(x,y))+(y-min(x,y))*c[6]+(x-min(x,y))*c[2]);
			ans=min(ans,c[1]*max(x,y)+(max(x,y)-y)*c[3]+(max(x,y)-x)*c[5]);
			ans=min(ans,c[2]*x+c[6]*y);
		}
		else if(x<=0&&y<=0)
		{
			x=-x,y=-y;
			ans=min(ans,c[4]*(min(x,y))+(y-min(x,y))*c[3]+(x-min(x,y))*c[5]);
			ans=min(ans,c[4]*max(x,y)+(max(x,y)-y)*c[6]+(max(x,y)-x)*c[2]);
			ans=min(ans,c[5]*x+c[3]*y);
		}
		else if(x>=0&&y<=0)
		{
			ans=c[2]*x-c[3]*y;
		}
		else if(x<=0&&y>=0)
		{
			ans=-c[5]*x+c[6]*y;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
///