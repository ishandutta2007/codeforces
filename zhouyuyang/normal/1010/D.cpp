#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=1000005;
int val[N],son[N][2];
int tp[N],fa[N],n;
char s[5]; 
void dfs(int x){
	fa[x]=x;
	if (!tp[x]) return;
	if (tp[x]==1){
		dfs(son[x][0]);
		fa[son[x][0]]=x;
		val[x]=val[son[x][0]]^1;
		return;
	}
	if (tp[x]==2){
		dfs(son[x][0]);
		dfs(son[x][1]);
		if (val[son[x][1]]) fa[son[x][0]]=x;
		if (val[son[x][0]]) fa[son[x][1]]=x;
		val[x]=val[son[x][0]]&val[son[x][1]];
		return;
	}
	if (tp[x]==3){
		dfs(son[x][0]);
		dfs(son[x][1]);
		if (!val[son[x][1]]) fa[son[x][0]]=x;
		if (!val[son[x][0]]) fa[son[x][1]]=x;
		val[x]=val[son[x][0]]|val[son[x][1]];
		return;
	}
	if (tp[x]==4){
		dfs(son[x][0]);
		dfs(son[x][1]);
		fa[son[x][0]]=x;
		fa[son[x][1]]=x;
		val[x]=val[son[x][0]]^val[son[x][1]];
		return;
	}
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		if (s[1]=='I') scanf("%d",&val[i]),tp[i]=0;
		else if (s[1]=='N') scanf("%d",&son[i][0]),tp[i]=1;
		else{
			scanf("%d%d",&son[i][0],&son[i][1]);
			if (s[1]=='A') tp[i]=2;
			if (s[1]=='O') tp[i]=3;
			if (s[1]=='X') tp[i]=4;
		}
	} 
	dfs(1);
	For(i,1,n) if (tp[i]==0)
		putchar((val[1]^(get(i)==1))+48);
}