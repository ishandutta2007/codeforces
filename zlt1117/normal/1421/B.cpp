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
const int maxn=205;
int T,n;
char a[maxn][maxn];
int main()
{
	T=gi();
	while(T--)
	{
		n=gi();
		FOR(i,1,n)scanf("%s",a[i]+1);
		if(a[1][2]==a[2][1])
		{
			int cnt=(a[n][n-1]==a[1][2])+(a[n-1][n]==a[1][2]);
			printf("%d\n",cnt);
			if(a[n][n-1]==a[1][2])printf("%d %d\n",n,n-1);
			if(a[n-1][n]==a[1][2])printf("%d %d\n",n-1,n);
		}
		else
		{
			if(a[n][n-1]==a[n-1][n])
			{
				printf("1\n");
				if(a[1][2]!=a[n-1][n])printf("2 1\n");
				else printf("1 2\n");
			}
			else
			{
				printf("2\n");
				if(a[1][2]=='0')printf("1 2\n");
				else if(a[2][1]=='0')printf("2 1\n");
				if(a[n][n-1]=='1')printf("%d %d\n",n,n-1);
				else if(a[n-1][n]=='1')printf("%d %d\n",n-1,n);
			}
		}
	}
	return 0;
}
/*
1
3 
S10
101
01T
*/