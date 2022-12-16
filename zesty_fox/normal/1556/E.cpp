#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
int n,q,a[N],b[N];

ll maxn[N][21],minx[N][21],lg2[N],sum[N];
void init(){
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) maxn[i][0]=minx[i][0]=sum[i];
	for(int j=1;j<=lg2[n];j++){
		for(int l=1;l<=n-(1<<j)+1;l++){
			maxn[l][j]=max(maxn[l][j-1],maxn[l+(1<<j-1)][j-1]);
			minx[l][j]=min(minx[l][j-1],minx[l+(1<<j-1)][j-1]);
		}
	}
}

ll query_min(int l,int r){
	int k=lg2[r-l+1];
	return min(minx[l][k],minx[r-(1<<k)+1][k]);
}

ll query_max(int l,int r){
	int k=lg2[r-l+1];
	return max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}

void solve(int l,int r){
	if(sum[r]!=sum[l-1]||query_min(l,r)<sum[l-1]) puts("-1");
	else printf("%lld\n",query_max(l,r)-sum[l-1]);
}

int main(){
	n=rdi(),q=rdi();
	for(int i=1;i<=n;i++) a[i]=rdi();
	for(int i=1;i<=n;i++){
		a[i]-=rdi();
		sum[i]=sum[i-1]-a[i];
	}
	init();
	while(q--){
		int l=rdi(),r=rdi();
		solve(l,r);
	}
    return 0;
}