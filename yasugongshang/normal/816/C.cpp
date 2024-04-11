#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#define For(i,j,k)	for(int i=j;i<=k;i++)
using namespace std;
inline void read(int &tx){   int x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(int x){    if (x<0) putchar('-'),x=-x; if(x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(int x){write(x);puts("");}
const int N=2001;
int n,m,a[N][N],ans1[10000001],ans2[10000001],tot,tot1;
inline void t_l()
{
	For(i,1,n)
	{
		int mi=1e9;
		For(j,1,m)	mi=min(mi,a[i][j]);
		For(j,1,mi)	ans1[++tot]=i;
		For(j,1,m)	a[i][j]-=mi;
	}
}
inline void t_r()
{
	For(i,1,m)
	{
		int mi=1e9;
		For(j,1,n)	mi=min(mi,a[j][i]);
		For(j,1,mi)	ans2[++tot1]=i;
		For(j,1,n)	a[j][i]-=mi;
	}
}
int main()
{
	read(n);read(m);
	For(i,1,n)
		For(j,1,m)	read(a[i][j]);
	if(n<m)	t_l(),t_r();
		else t_r(),t_l();
	For(i,1,n)For(j,1,m)if(a[i][j])	{puts("-1");return 0;}
	writeln(tot1+tot);
	For(i,1,tot)printf("row %d\n",ans1[i]);
	For(i,1,tot1)printf("col %d\n",ans2[i]);
}