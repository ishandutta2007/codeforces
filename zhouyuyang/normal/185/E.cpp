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
const int M=2000005;
const int N=100005;
int ls[M],rs[M],sum[M];
int limit,sz,rt[N];
void insert(int &k,int l,int r,int p){
	if (k<=limit){
		ls[++sz]=ls[k]; rs[sz]=rs[k];
		sum[sz]=sum[k]; k=sz;
	}
	sum[k]++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p); 
}
int ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return sum[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+
		   ask(rs[k],mid+1,r,mid+1,y); 
}

int n,k;
struct P{
	int X,Y;
}a[N],b[N];
int X[N],Y[N*2];
vector<int> vec[N];
bool ask(int lx,int rx,int ly,int ry){
	lx=LB(X+1,X+*X+1,lx)-X;
	rx=UB(X+1,X+*X+1,rx)-X-1;
	ly=LB(Y+1,Y+*Y+1,ly)-Y;
	ry=UB(Y+1,Y+*Y+1,ry)-Y-1;
	return ask(rt[rx],1,*Y,ly,ry)!=
		   ask(rt[lx-1],1,*Y,ly,ry);
}


pii mn[N],q[N*2];
int t[N*2];
void change(int x,int v){
	for (;x<=*Y;x+=x&(-x)) t[x]=max(t[x],v);
}
int ask(int x){
	int ans=-INF;
	for (;x;x-=x&(-x)) ans=max(ans,t[x]);
	return ans;
}

void findclosest(){
	For(i,1,n) mn[i]=pii(INF/2,i);
	For(T,0,3){
		For(i,1,n){
			P tmp=(P){a[i].Y,-a[i].X};
			a[i]=tmp;
		}
		For(i,1,k){
			P tmp=(P){b[i].Y,-b[i].X};
			b[i]=tmp;
		}
		*Y=0;
		For(i,1,n) Y[++*Y]=a[i].Y;
		For(i,1,k) Y[++*Y]=b[i].Y;
		sort(Y+1,Y+*Y+1);
		*Y=unique(Y+1,Y+*Y+1)-Y-1;
		For(i,1,*Y) t[i]=-INF;
		For(i,1,n) q[i]=pii(a[i].X,i);
		For(i,1,k) q[n+i]=pii(b[i].X,~i);
		sort(q+1,q+n+k+1);
		For(i,1,n+k){
			int id=q[i].se;
			if (id<0){
				id=~id;
				change(LB(Y+1,Y+*Y+1,b[id].Y)-Y,b[id].X+b[id].Y);
			}
			else{
				int v=ask(LB(Y+1,Y+*Y+1,a[id].Y)-Y);
				mn[id].fi=min(mn[id].fi,a[id].X+a[id].Y-v);
			}
		}
	}
}
bool cmp(pii a,pii b){
	if (a.fi==b.fi) return a.se>b.se;
	return a.fi>b.fi;
} 
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
	For(i,1,k) scanf("%d%d",&b[i].X,&b[i].Y);
	findclosest();
	For(i,1,n) a[i]=(P){a[i].X+a[i].Y,a[i].X-a[i].Y};
	For(i,1,k) b[i]=(P){b[i].X+b[i].Y,b[i].X-b[i].Y};
	*X=*Y=0;
	For(i,1,k){
		X[++*X]=b[i].X;
		Y[++*Y]=b[i].Y;
	}
	X[++*X]=Y[++*Y]=INF;
	X[++*X]=Y[++*Y]=-INF;
	sort(X+1,X+*X+1);
	sort(Y+1,Y+*Y+1);
	*X=unique(X+1,X+*X+1)-X-1;
	*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,1,k){
		int x=LB(X+1,X+*X+1,b[i].X)-X;
		vec[x].PB(i); 
	}
	For(i,1,*X){
		rt[i]=rt[i-1];
		For(j,0,vec[i].size()-1){
			int id=vec[i][j];
			int y=LB(Y+1,Y+*Y+1,b[id].Y)-Y;
			insert(rt[i],1,*Y,y);
		}
		limit=sz;
	}
	
	sort(mn+1,mn+n+1,cmp);
	int l=0,r=INF/2,ans=INF/2;
	while (l<=r){
		int mid=(l+r)/2;
		int lx=-(INF/4),rx=-lx;
		int ly=lx,ry=rx;
		bool ok=0;
		For(i,1,n){
			int id=mn[i].se;
			int dis=mid-mn[i].fi;
			if (dis>=0){
				ok|=ask(lx-dis,rx+dis,ly-dis,ry+dis);
				if (ok) break;
			}
			lx=max(lx,a[id].X-mid);
			rx=min(rx,a[id].X+mid);
			ly=max(ly,a[id].Y-mid);
			ry=min(ry,a[id].Y+mid);
			if (lx>rx||ly>ry) break;
		}
		ok|=(lx<=rx&&ly<=ry);
		if (ok) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}