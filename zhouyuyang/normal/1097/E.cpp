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
const int N=100005;
int a[N],lim[N],n;
int pre[N],v[N],f[N],vis[N];
vector<int> tmp[555];
vector<vector<int>> ans;
void solve(){
	ans.clear();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	for (;n;){
		For(i,0,n) pre[i]=v[i]=0;
		int mx=0;
		For(i,1,n)
			if (a[i]>a[v[mx]])
				f[i]=++mx,v[mx]=i,pre[i]=v[mx-1];
			else{
				int l=1,r=mx,ans=0;
				while (l<=r){
					int mid=(l+r)/2;
					if (a[v[mid]]<a[i])
						ans=mid,l=mid+1;
					else r=mid-1;
				}
				pre[i]=v[ans];
				v[f[i]=ans+1]=i;
			}
		if (mx>=lim[n]){
			For(i,1,n) vis[i]=0;
			tmp[1].clear();
			for (int i=v[mx];i;i=pre[i])
				tmp[1].PB(a[i]),vis[i]=1;
			int nn=0;
			For(i,1,n) if (!vis[i])
				a[++nn]=a[i];
			n=nn;
			reverse(tmp[1].begin(),tmp[1].end());
			ans.PB(tmp[1]); 
		}
		else{
			int mx=0;
			For(i,1,n){
				int at=mx+1,val=1e9;
				For(j,1,mx) if (v[j]>=a[i]&&v[j]<=val)
					at=j,val=v[j];
				v[at]=a[i];
				if (at>mx)
					tmp[++mx].clear();
				tmp[at].PB(a[i]);
			}
			//printf("%d %d %d\n",mx,n,lim[n]);
			assert(mx<=lim[n]);
			For(i,1,mx)
				ans.PB(tmp[i]);
			break;
		}
	}
	printf("%d\n",ans.size());
	for (auto i:ans){
		printf("%d ",i.size());
		For(j,0,i.size()-1)
			printf("%d ",i[j]);
		puts("");
	}
}
int main(){
	For(i,1,N-1)
		for (lim[i]=lim[i-1];lim[i]*(lim[i]+1)<2*i;lim[i]++);
	int T; scanf("%d",&T);
	while (T--) solve();
}