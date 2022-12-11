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
int n,w,h; pii ta[SZ],tb[SZ],rr[SZ],s[SZ],tg[SZ];
vector<int> A_[333333],*A=A_+111111;
vector<int> B_[333333],*B=B_+111111;
bool cmp(int a,int b) {return s[a]<s[b];}
void work(int x)
{
	if(A[x].size()||B[x].size());else return;
	sort(A[x].begin(),A[x].end(),cmp);
	sort(B[x].begin(),B[x].end(),cmp);
	int g=0,p=1;
	for(auto s:A[x]) tg[++g]=ta[s];
	for(int _=int(B[x].size())-1;_>=0;--_)
	{
		int s=B[x][_]; tg[++g]=tb[s];
	}
	for(int _=int(B[x].size())-1;_>=0;--_)
	{
		int s=B[x][_]; rr[s]=tg[p++];
	}
	for(auto s:A[x]) rr[s]=tg[p++];
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;++i)
	{
		int g,p,t;
		scanf("%d%d%d",&g,&p,&t);
		s[i]=pii(p,t);
		if(g==1) A[p-t].pb(i),ta[i]=pii(p,h);
		else B[p-t].pb(i),tb[i]=pii(w,p);
	}
	for(int i=-100000;i<=200000;++i)
		work(i);
	for(int i=1;i<=n;++i)
		printf("%d %d\n",rr[i].fi,rr[i].se);
}