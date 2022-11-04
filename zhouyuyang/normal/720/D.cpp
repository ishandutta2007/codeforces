#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int D=1000005;
const int N=100005;
const int mo=1000000007;
int tg[D*3],sum[D*3];
void pushdown(int k){
	if (!tg[k]) return;
	sum[k*2]=sum[k*2+1]=0;
	tg[k*2]=tg[k*2+1]=1;
	tg[k]=0;
} 
void pushup(int k){
	sum[k]=(sum[k*2]+sum[k*2+1])%mo;
}
void change(int k,int l,int r,int p,int v){
	if (l==r) return sum[k]=v,void(0);
	int mid=(l+r)/2;
	pushdown(k);
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	pushup(k);
}
void cover(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		tg[k]=1; sum[k]=0;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) cover(k*2,l,mid,x,y);
	else if (x>mid) cover(k*2+1,mid+1,r,x,y);
	else cover(k*2,l,mid,x,mid),cover(k*2+1,mid+1,r,mid+1,y);
	pushup(k);
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return sum[k];
	int mid=(l+r)/2; pushdown(k);
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return (ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y))%mo;
}
struct rect{
	int x,y,X,Y,v;
}a[N];
vector<int> IN[D],OUT[D];
set<pii > s;
int n,m,k;
bool cmp(rect a,rect b){
	return a.y<b.y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,k) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].X,&a[i].Y);
	sort(a+1,a+k+1,cmp);
	For(i,1,k){
		IN[a[i].x].PB(i);
		OUT[a[i].X+1].PB(i);
	}
	s.insert(pii(0,0));
	For(i,1,n){
		if (IN[i].size()){
			int sz=IN[i].size();
			For(j,0,sz-1){
				int id=IN[i][j];
				int id2=(*s.LB(pii(-a[id].Y-1,0))).se;
				if (a[id2].Y<a[id].Y+1&&a[id].Y<m)
					a[id].v=ask(1,1,m,a[id2].Y+1,a[id].Y+1);
				else a[id].v=-1;
			}
			For(j,0,sz-1){
				int id=IN[i][j];
				if (a[id].v>=0) change(1,1,m,a[id].Y+1,a[id].v);
				cover(1,1,m,a[id].y,a[id].Y);
				s.insert(pii(-a[id].Y,id));
				s.insert(pii(-a[id].y,id));
			}
		}
		if (OUT[i].size()){
			int sz=OUT[i].size();
			For(j,0,sz-1){
				int id=OUT[i][j];
				s.erase(pii(-a[id].Y,id));
				s.erase(pii(-a[id].y,id));
			}
		}
		if (i==1) change(1,1,m,1,1);
	}
	int u=-(*s.LB(pii(-m,0))).fi;
	printf("%d\n",ask(1,1,m,u+1,m));
}