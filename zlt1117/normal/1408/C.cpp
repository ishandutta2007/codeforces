#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define int long long
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int T,n,l;
double a[maxn];
signed main()
{
	T=gi();
	while(T--)
	{
		n=gi(),l=gi();
		FOR(i,1,n)a[i]=gi();
		double ans=0;
		double fir=0,sec=l;
		int spe1=1,spe2=1;
		int l1=0,r1=n+1;
		while(l1<r1-1)
		{
			double tim1=fabs(a[l1+1]-fir)/(double)(spe1);
			double tim2=fabs(a[r1-1]-sec)/(double)(spe2);
			if(fabs(tim1-tim2)<1e-10)
			{
				l1++,r1--;
				spe1++,spe2++;
				fir=a[l1],sec=a[r1];
			}
			else
			{
				if(tim1>tim2)
				{
					spe2++,r1--;
					sec=a[r1];
					fir+=tim2*spe1;
				}
				else
				{
					spe1++,l1++;
					fir=a[l1];
					sec-=tim1*spe2;
				}
			}
			ans+=min(tim1,tim2);
		}
		ans+=fabs(fir-sec)/(double)(spe1+spe2);
		printf("%.15lf\n",ans);
		FOR(i,1,n)a[i]=0;
	}
	return 0;
}