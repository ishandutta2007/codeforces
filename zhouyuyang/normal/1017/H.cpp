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
#define vi vector<int>
const int mo=998244353;
int power(int x,int y){
	int s=1;
	for (;y;){
		if (y&1) s=1ll*s*x%mo;
		if (y/=2) x=1ll*x*x%mo;
	}
	return s;
}
const int N=100005,blk=200;
int fac[N*2],inv[N*2]; 
int freq[N],cnt[N];
int e[N],ans[N];
int n,m,Q;
vi heavy;
struct que{
	int l,r,k,id;
}q[N];
void add(int x){
	cnt[freq[x]]--;
	cnt[++freq[x]]++;
}
void del(int x){
	cnt[freq[x]]--;
	cnt[--freq[x]]++;
}
bool cmpk(que a,que b){
	return pii(a.k,a.l-a.r)<pii(b.k,b.l-b.r);
}
bool cmpmo(que a,que b){
	return pii(a.l/blk,a.r)<pii(b.l/blk,b.r);
}
int main(){
	fac[0]=inv[0]=1;
	For(i,1,N*2-1){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=power(fac[i],mo-2);
	}
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n){
		scanf("%d",&e[i]);
		cnt[e[i]]++;
	}
	For(i,1,m)
		if (cnt[i]>=blk)
			heavy.PB(i);
	For(i,1,Q){
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
		q[i].id=i;
	}
	sort(q+1,q+Q+1,cmpk);
	for (int r=1;r<=Q;){
		int l=r,kk=q[l].k,v=1;
		int v2=1ll*m*kk%mo,las=n;
		for (;r<=Q&&kk==q[r].k;r++);
		For(i,1,m) v=1ll*v*fac[kk+cnt[i]]%mo;
		For(i,l,r-1){
			int len=q[i].r-q[i].l+1;
			for (;las>len;v=1ll*(++v2)*v%mo,las--);
			ans[q[i].id]=v;
		}
	}
	sort(q+1,q+Q+1,cmpmo);
	CLR(cnt,0); cnt[0]=m;
	int l=1,r=0;
	For(i,1,n) add(e[i]);
	For(i,1,Q){
		for (;q[i].l<l;del(e[--l]));
		for (;q[i].r>r;del(e[++r]));
		for (;q[i].l>l;add(e[l++]));
		for (;q[i].r<r;add(e[r--]));
		int res=1;
		For(j,0,blk-1) if (cnt[j])
			res=1ll*res*power(inv[q[i].k+j],cnt[j])%mo;
		for (int j:heavy) if (freq[j]>=blk)
			res=1ll*res*inv[q[i].k+freq[j]]%mo;
		ans[q[i].id]=1ll*ans[q[i].id]*res%mo;
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}