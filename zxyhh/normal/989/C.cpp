#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
int a[5],n=4,m;
int t[55][55];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	rep(i,1,4) a[i]=rd();
	rep(i,1,n) {
		if (a[i]>0) a[i]--,m++;else continue;
		rep(j,(m-1)*8+1,m*8) rep(k,1,50) t[j][k]=i;
		int tc=i+2;
		if (tc>n)tc-=n;
		for(int j=(m-1)*8+2;j<=m*8;j+=2) for(int k=1;k<=50;k+=2) 
		if (a[tc]>1||(a[tc]==1&&tc<i)) t[j][k]=tc,a[tc]--; 
	}
	wrt(m*8,' ');wrt(50,'\n');
	rep(i,1,m*8){
		rep(j,1,50) putchar((char)t[i][j]+'A'-1);
		putchar('\n');
	}
}