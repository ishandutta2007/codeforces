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
int n,c,d,b[SZ],p[SZ]; char s[SZ][2];
struct B
{
int mx[SZ];
void init()
{
	memset(mx,-127/3,sizeof(mx));
}
void edt(int x,int y)
{
	for(;x<=100000;x+=x&-x) mx[x]=max(mx[x],y);
}
int gm(int x)
{
	if(x<=0) return -1e9;
	int ans=-1e9;
	for(;x>=1;x-=x&-x) ans=max(ans,mx[x]);
	return ans;
}
}C,D;
int main()
{
	C.init(); D.init();
	scanf("%d%d%d",&n,&c,&d);
	int ans=0,m1=-1e9,m2=-1e9;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%s",b+i,p+i,s[i]);
		if(s[i][0]=='C')
		{
			if(p[i]<c)
				ans=max(ans,C.gm(c-p[i])+b[i]);
			if(p[i]<=c) m1=max(m1,b[i]);
			C.edt(p[i],b[i]);
		}
		else
		{
			if(p[i]<d)
				ans=max(ans,D.gm(d-p[i])+b[i]);
			if(p[i]<=d) m2=max(m2,b[i]);
			D.edt(p[i],b[i]);
		}
	}
	ans=max(ans,m1+m2);
	printf("%d\n",ans);
}