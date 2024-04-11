#pragma GCC optimize(4)
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
int T,x_1,y_1,x_2,y_2;
int main()
{
	T=gi();
	while(T--)
	{
		int ans=0;
		x_1=gi(),y_1=gi(),x_2=gi(),y_2=gi();
		if(x_1>x_2)swap(x_1,x_2);
		if(y_1>y_2)swap(y_1,y_2);
		if(x_1!=x_2)ans+=x_2-x_1;
		else {printf("%d\n",y_2-y_1);continue;}
		if(y_2==y_1){printf("%d\n",ans);continue;}
		else printf("%d\n",ans+2+y_2-y_1);
	}
	return 0;
}