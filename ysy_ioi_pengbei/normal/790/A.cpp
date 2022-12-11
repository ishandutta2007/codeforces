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
int n,k,ff[SZ];
int gf(int x){return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{
	int ga=gf(a),gb=gf(b);
	if(ga^gb) ff[ga]=gb;
}
char s[SZ];
string sp,ss[SZ];
int main()
{
	for(int i=0;i<10;i++) sp.pb('a'+i);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-k+1;i++)
	{
		scanf("%s",s);
		if(s[0]=='N') uni(i,i+k-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(gf(i)==i)
		{
			ss[i]=sp;
			ss[i][0]=toupper(ss[i][0]);
			next_permutation(sp.begin(),sp.end()); 
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ss[gf(i)]<<" ";
}