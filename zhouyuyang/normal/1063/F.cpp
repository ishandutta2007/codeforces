#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define INF (1<<29)
using namespace std;
const int N=500005;
int n,ans,f[N];
ll P[N],hsh[N];
char s[N];
set<ll> S;
ll gethsh(int l,int r){
	return hsh[r]-hsh[l]*P[r-l];
}
bool check(int p,int x){
	ll t=gethsh(p-x+1,p);
	if (S.find(t)!=S.end()) return 1;
	t=gethsh(p-x,p-1);
	return S.find(t)!=S.end(); 
}
void insert(int x){
	for (int i=f[x];i;i--){
		ll v=gethsh(x-i,x);
		if (S.find(v)!=S.end()) return;
		S.insert(v);
	}
} 
int main(){
	scanf("%d%s",&n,s+1);
	reverse(s+1,s+n+1);
	P[0]=1;
	For(i,1,n){
		P[i]=P[i-1]*137;
		hsh[i]=hsh[i-1]*137+s[i];
	}
	S.insert(0);
	For(i,1,n){
		f[i]=f[i-1]+1;
		for (;f[i]&&!check(i,f[i]);)
			insert(i-(--f[i]));
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
}