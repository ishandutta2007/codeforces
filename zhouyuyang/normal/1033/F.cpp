#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
int w,n,Q,V[15];
int c[1<<12],id[1<<12];
int f[555555];
int dfs(char *g,int s,int t){
	if (!*g) return c[s]*f[t];
	s<<=1,t*=3;
	switch(*g++){
		case'A':return dfs(g,s,t+2)+dfs(g,s+1,t);
		case'O':return dfs(g,s,t);
		case'X':return dfs(g,s,t)+dfs(g,s+1,t+1);
		case'a':return dfs(g,s+1,t+1);
		case'o':return dfs(g,s,t+1)+dfs(g,s+1,t+2);
		case'x':return dfs(g,s,t+1)+dfs(g,s+1,t);
	}
}
int main(){
	scanf("%d%d%d",&w,&n,&Q);
	for (int i=1;i<1<<w;i++)
		id[i]=id[i/2]*3+(i&1);
	while (n--){
		int x; scanf("%d",&x);
		c[x]++; f[id[x]]++;
	}
	V[0]=1;
	for (int i=1;i<=w;i++) V[i]=V[i-1]*3;
	for (int i=0;i<w;i++)
		for (int j=0;j<V[w];j++)
			if (j/V[i]%3==2)
				f[j]+=f[j-V[i]]+f[j-V[i]*2];
	while (Q--){
		char s[15];
		scanf("%s",s);
		printf("%d\n",dfs(s,0,0));
	}
}