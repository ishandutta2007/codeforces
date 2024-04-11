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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=100005;
char s[N];
int pl[N][26],pr[N][26],n;
int pre[N][26],suf[N][26],Xor[N];
int calc(int l,int r){
	int msk=0;
	For(j,0,25) if (pr[l][j]<=r){
		int w=Xor[pl[r][j]]^Xor[pr[l][j]]^suf[l][j]^pre[r][j];
		msk|=(1<<w);
	}
	For(j,0,26)
		if (!(msk&(1<<j))) return j;
}
pii seg[55+N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) s[i]-='a';
	For(i,1,n) For(j,0,25)
		pl[i][j]=(s[i]==j?i:pl[i-1][j]);
	For(j,0,25) pr[n+1][j]=n+1;
	Rep(i,n,1) For(j,0,25)
		pr[i][j]=(s[i]==j?i:pr[i+1][j]);
	For(i,1,n){
		int cnt=0;
		Xor[i]=Xor[pl[i-1][s[i]]]^pre[i-1][s[i]];
		For(j,0,25) if (pl[i][j]!=i&&pl[i][j])
			seg[++cnt]=pii(pl[i][j]+1,0);
		if (i!=n){
			int L=pl[i][s[i+1]];
			For(j,L+1,i) seg[++cnt]=pii(j,1);
		}
		sort(seg+1,seg+cnt+1,greater<pii >());
		For(j,1,cnt){
			int w=calc(seg[j].fi,i);
			if (seg[j].se)
				suf[seg[j].fi][s[i+1]]=w;
			else pre[i][s[seg[j].fi-1]]=w;
		}
	}
	int Q; scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		puts(calc(l,r)?"Alice":"Bob");
	}
}