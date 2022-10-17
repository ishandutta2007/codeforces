#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10,mod=1e9+7;
int tl[M],tr[M],n;
struct node{
	int sz;
	LL sl,sr,slx,srx,slr,slxr,slrx,sum;
	void init(int x){
		if (!x){
			sz=sl=sr=slx=srx=slr=slxr=slrx=sum=0;
			return ;
		}
		sz=1; sl=slx=tl[x]; sr=srx=tr[x]; slr=slxr=slrx=sum=0;
	}
	
}t[M*6],tmp[M];
node operator +(node A,node B){
	node C; C.sz=A.sz+B.sz;
	C.sl=(A.sl+B.sl)%mod;
	C.sr=(A.sr+B.sr)%mod;
	C.slx=(A.slx+B.slx+B.sl*A.sz)%mod;
	C.srx=(A.srx+B.srx+B.sr*A.sz)%mod;
	C.slr=(A.slr+B.slr+A.sl*B.sr)%mod;
	C.slxr=(A.slxr+(B.slxr+B.slr*A.sz)+A.slx*B.sr)%mod;
	C.slrx=(A.slrx+(B.slrx+B.slr*A.sz)+A.sl*(B.srx+B.sr*A.sz%mod))%mod;
	C.sum=(C.slrx+mod*2-C.slxr-C.slr)%mod;
	return C;
}
int tot,L[M*6],R[M*6];
#define lc L[x]
#define rc R[x]
#define mid (l+r>>1)
void pu(int x){
	t[x]=t[lc]+t[rc];
}
void build(int &x,int l,int r){
	x=++tot;
	if (l==r){
		t[x]=tmp[l];
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x);
}
void upd(int x,int l,int r,int p,int o){
	if (l==r){
		t[x].init(o); 
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p,o);
	else upd(rc,mid+1,r,p,o);
	pu(x);
}
vector<int> v[M];

struct BIT{
	#define lowbit(x) (x&-x)
	int d[M];
	void clr(){
		ms(d,0);
	}
	void add(int x){
		for (;x<=n;x+=lowbit(x)) d[x]++;
	}
	int qry(int x){
		int ret=0;
		for (;x;x-=lowbit(x)) ret+=d[x];
		return ret;
	}
}bit;
int a[M],ti[M],num[M],rt[M],ps[M],m;
bool ban[M];
int main(){
//	freopen("count2.in","r",stdin);
//	freopen("count2.out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read(),ti[i]=a[i];
	sort(ti+1,ti+n+1);
	int N=unique(ti+1,ti+n+1)-ti-1;
	F(i,1,n){
		a[i]=lower_bound(ti+1,ti+N+1,a[i])-ti;
		v[a[i]].pb(i);
	}
	bit.clr();
	F(i,1,n){
		tl[i]=bit.qry(a[i]);
		bit.add(a[i]);
	}
	bit.clr();
	DF(i,n,1){
		tr[i]=bit.qry(a[i]);
		bit.add(a[i]);
	}
	LL cur=0;
	F(i,1,N){
		num[i]=SZ(v[i])+1;
		F(j,1,num[i]){
			tmp[j].init(v[i][j-1]);
			ps[v[i][j-1]]=j;
		}
		build(rt[i],1,num[i]);
		cur=(cur+t[rt[i]].sum)%mod;
	}
	m=read();
	F(i,1,m){
		int opt=read(),x=read();
		if (opt==1){
			if (!ban[x]){
				cur=(cur+mod-t[rt[a[x]]].sum)%mod;
				upd(rt[a[x]],1,num[a[x]],ps[x],0);
				cur=(cur+t[rt[a[x]]].sum)%mod;
				ban[x]=1;
			}
		}
		else{
			if (ban[x]){
				cur=(cur+mod-t[rt[a[x]]].sum)%mod;
				upd(rt[a[x]],1,num[a[x]],ps[x],x);
				cur=(cur+t[rt[a[x]]].sum)%mod;
				ban[x]=0;
			}
		}
		cout<<cur<<"\n";
	}
    return 0;
}
/*
6
1 1 1 1 1 1
2
1 3
2 3

8
1 1 1 1 1 1 1 1 
4
1 2
1 3
2 3
2 2 
*/