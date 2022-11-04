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

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005,S=500;
int n,id,a[N],val[N];
int F[205][N],G[205][N];
map<int,int> mp;
int get(int x){
	if (mp.find(x)==mp.end())
		val[++id]=x,mp[x]=id;
	return mp[x];
}
int main(){
	scanf("%d",&n);
	int cnt=(n-1)/S+1;
	For(i,1,n) scanf("%d",&a[i]),a[i]=get(a[i]);
	For(i,1,cnt){
		int L=(i-1)*S+1,R=min(i*S,n);
		CPY(F[i],F[i-1]); CPY(G[i],G[i-1]);
		For(j,L,R) G[i][++F[i][a[j]]]++;
	}
	int Q; scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		int be=(y-1)/S,beg=be*S+1;
		if (tp==1){
			For(i,be+1,cnt) G[i][F[i][a[y]]--]--;
			a[y]=get(x);
			For(i,be+1,cnt) G[i][++F[i][a[y]]]++;
		}
		else{
			x=(x&1)+(x>1?2:0);
			if (x==1) printf("%d\n",val[a[y]]);
			else{
				For(i,beg,y) G[be][++F[be][a[i]]]++;
				printf("%d\n",x==2?F[be][a[y]]:G[be][F[be][a[y]]]);
				For(i,beg,y) G[be][F[be][a[i]]--]--;
			}
		}
	}
}