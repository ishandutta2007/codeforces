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
#include <deque> 
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
char s[SZ],t[SZ]; 
int ss[SZ],h=0,r;
int main()
{
	scanf("%s%s",s,t);
	int n=strlen(s),a=(n+1)>>1;
	sort(s,s+n);sort(t,t+n);reverse(t,t+n);
	int c=0,L1=0,R1=a-1,L2=0,R2=n-a-1; r=n-1;
	for(unsigned g=0;g<n;g++)
	{
		if(s[L1]<::t[L2]) ss[h++]=s[L1++];
		else ss[r--]=s[R1--];
		if(++c>=n) break;
		if(t[L2]>::s[L1]) ss[h++]=t[L2++];
		else ss[r--]=t[R2--];
		if(++c>=n) break;
	}
	for(int i=0;i<n;i++) putchar(ss[i]);
	puts("");
}