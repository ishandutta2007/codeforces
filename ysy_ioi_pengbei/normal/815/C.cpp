#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,b,p1[SZ],p2[SZ],sz[SZ]; Edg
ll f[5005][2][5005],tmp[5005];
void dp(int x,int fa=0)
{
	int s=1;
	f[x][0][0]=0; f[x][0][1]=p1[x];
	f[x][1][1]=p2[x];
	for esb(x,e,y) if(y!=fa)
	{
		dp(y,x);
		int ns=s+sz[y];
		{
			for(int j=0;j<=ns;j++) tmp[j]=1e18;
			for(int a=0;a<=s;a++)
				for(int b=0;b<=sz[y];b++)
					tmp[a+b]=min(tmp[a+b],f[x][0][a]+f[y][0][b]);
			for(int j=0;j<=ns;j++) f[x][0][j]=tmp[j];
		}
		{
			for(int j=0;j<=ns;j++) tmp[j]=1e18;
			for(int a=0;a<=s;a++)
				for(int b=0;b<=sz[y];b++)
					tmp[a+b]=min(tmp[a+b],f[x][1][a]
					+min(f[y][0][b],f[y][1][b]));
			for(int j=0;j<=ns;j++) f[x][1][j]=tmp[j];
		}
		s=ns;
	}
	sz[x]=s;
}
int main()
{
	memset(f,127/3,sizeof f);
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",p1+i,p2+i);
		p2[i]=p1[i]-p2[i];
		if(i>=2)
		{
			int x;
			scanf("%d",&x);
			ad_de(x,i);
		}
	}
	dp(1); int rs=0;
	for(int i=0;i<=n;i++)
		if(f[1][0][i]<=b||f[1][1][i]<=b) rs=i;
	printf("%d\n",rs);
}