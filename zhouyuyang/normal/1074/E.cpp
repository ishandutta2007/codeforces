#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db double
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
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;

vector<vector<int>> ans;
pair<int,int> pos[405];
int a[25][25],n,m;
void move(vector<int> p){
	ans.push_back(p);
	int sz=p.size();
	Rep(i,sz-2,0){
		swap(pos[p[i]],pos[p[sz-1]]);
		pii x;
		x=pos[p[i]];
		a[x.fi][x.se]=p[i];
		x=pos[p[sz-1]];
		a[x.fi][x.se]=p[sz-1];
	}
}
void roL(int x,int y){
	move(vector<int>{
		a[x][y],a[x+1][y],
		a[x+1][y+1],a[x][y+1]
	});
}
void roR(int x,int y){
	move(vector<int>{
		a[x][y],a[x][y+1],
		a[x+1][y+1],a[x+1][y]
	});
}
void goL(int v){
	int x=pos[v].fi,y=pos[v].se;
	move(vector<int>{
		a[x][y],a[x][y-1],
		a[(x!=n?x+1:x-1)][y-1],a[(x!=n?x+1:x-1)][y]
	});
}
void goR(int v){
	int x=pos[v].fi,y=pos[v].se;
	move(vector<int>{
		a[x][y],a[x][y+1],
		a[(x!=n?x+1:x-1)][y+1],a[(x!=n?x+1:x-1)][y]
	});
}
void goU(int v){
	int x=pos[v].fi,y=pos[v].se;
	move(vector<int>{
		a[x][y],a[x-1][y],
		a[x-1][(y==m?y-1:y+1)],a[x][(y==m?y-1:y+1)]
	});
}
void goD(int v){
	int x=pos[v].fi,y=pos[v].se;
	move(vector<int>{
		a[x][y],a[x+1][y],
		a[x+1][(y==m?y-1:y+1)],a[x][(y==m?y-1:y+1)]
	});
}
pii id[405];
int tot;
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&m);
 	For(i,1,n) For(j,1,m){
		scanf("%d",&a[i][j]);
		pos[a[i][j]]=pii(i,j);
	}
	For(i,1,n-1) For(j,1,m-1) id[++tot]=pii(i,j);
	random_shuffle(id+1,id+tot+1);
	For(i,1,tot)
		if (rand()&1) roL(id[i].fi,id[i].se);
		else roR(id[i].fi,id[i].se); 
	For(i,1,n-2){
		For(j,1,m-1){
			int x=(i-1)*m+j;
			for (;pos[x].se>j;) goL(x);
			for (;pos[x].se<j;) goR(x);
			for (;pos[x].fi>i;) goU(x);
		}
		int x=i*m;
		if (pos[x]==pii(i,m)) continue;
		if (pos[x]==pii(i+1,m-1)) roL(i+1,m-1);
		roR(i,m-1);
		for (;pos[x].se<m;goR(x));
		for (;pos[x].fi>i+1;goU(x));
		roL(i,m-1);
	}
	For(j,1,m-2){
		int x=(n-2)*m+j;
		for (;pos[x].se>j;) goL(x);
		for (;pos[x].fi>n-1;) goU(x);
		x=(n-1)*m+j;
		if (pos[x]==pii(n,j)) continue;
		if (pos[x]==pii(n-1,j+1)) roR(n-1,j+1);	
		roL(n-1,j);
		for (;pos[x].fi<n;goD(x));
		for (;pos[x].se>j+1;goL(x));
		roR(n-1,j);
	}
	for (;a[n-1][m-1]!=(n-1)*m-1;) roL(n-1,m-1);
	for (;;){
		bool ok=1;
		For(i,1,n) For(j,1,m)
			if (a[i][j]!=(i-1)*m+j) ok=0;
		if (ok) break;
		int tp=rand()%3;
		if (tp==0) roL(n-1,m-1);
		if (tp==1) roL(n-1,m-2);
		if (tp==2)
			move(vector<int>{
				a[n-1][m-2],a[n-1][m-1],a[n-1][m],
				a[n][m],a[n][m-1],a[n][m-2]
			});
	}
	printf("%d\n",ans.size());
	for (auto p:ans){
		printf("%d ",p.size());
		for (auto q:p) printf("%d ",q);
		puts("");
	}
}