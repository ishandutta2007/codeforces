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
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
bool check(int x){
	for (;x;x/=10)
		if (x%10!=4&&x%10!=7)
			return 0;
	return 1;
}
const int N=100005;
int a[N],n;
vector<int> pos;
int nxt[N];
int main(){
	scanf("%d",&n);
	pos.PB(0);
	For(i,1,n){
		scanf("%d",&a[i]);
		if (check(a[i])) pos.PB(i);
	}
	ll ans=1ull*(n+2)*(n+1)/2*n/3*(n-1)/4;
	For(i,1,pos.size()-1){
		nxt[i]=pos.size();
		Rep(j,pos.size()-1,i+1)
			if (a[pos[i]]==a[pos[j]])
				nxt[i]=j;
	}
	For(i,1,pos.size()-2){
		set<int> S;
		S.insert(pos[i]); S.insert(n+1);
		ll cur=0,R=pos[i+1]-pos[i];
		Rep(j,i,1){
			if (nxt[j]>i)
				for (int k=nxt[j];k<pos.size();k=nxt[k]){
					set<int>::iterator pre,nxt;
					pre=nxt=S.insert(pos[k]).fi;
					--pre; ++nxt;
					if (pre==S.begin()) cur+=1ll*(*nxt-pos[k])*(1ll*R*(R+1)/2+1ll*(pos[k]-pos[i+1])*R);
					else cur+=1ll*(*nxt-pos[k])*(pos[k]-*pre)*R;
				}
			ans-=cur*(pos[j]-pos[j-1]);
		}
	}
	printf("%lld\n",ans);
}