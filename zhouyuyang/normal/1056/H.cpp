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
#define INF (1ll<<60)
using namespace std;
const int N=300005,BLK=1000;
vector<int> vec[N],V[N];
int vis[N],n,Q;
bool solve(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) V[i].clear();
	For(i,1,Q){
		int sz; scanf("%d",&sz);
		vec[i].resize(sz);
		For(j,0,sz-1) scanf("%d",&vec[i][j]);
		if (sz<=BLK) for (auto j:vec[i]) V[j].PB(i);
	}
	For(i,1,n) vis[i]=0;
	For(i,1,n){
		for (auto j:V[i]){
			int flag=0;
			For(l,0,vec[j].size()-1)
				if (flag)
					if (!vis[vec[j][l]])
						vis[vec[j][l]]=vec[j][flag];
					else if (vis[vec[j][l]]!=vec[j][flag])
						return 0;
					else;
				else if (vec[j][l]==i) flag=l+1;
		}
		for (auto j:V[i]) for (auto k:vec[j]) vis[k]=0;
	}
	For(i,1,Q) if (vec[i].size()>BLK){
		For(j,1,n) vis[j]=-1;
		For(j,0,vec[i].size()-1) vis[vec[i][j]]=j;
		For(j,1,Q) if (vec[j].size()<=BLK||j>i){
			int mx=0;
			Rep(k,vec[j].size()-1,0)
				if (vis[vec[j][k]]>=0)
					if (vis[vec[j][k]]<mx)
						if (vec[i][vis[vec[j][k]]+1]!=vec[j][k+1])
							return 0;
						else;
					else mx=vis[vec[j][k]];
		}
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) puts(solve()?"Robot":"Human");
}