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
const ll INF=4e18;
int n,m;
ll a[N],x[N],y[N],sum;
int main(){
	n=rdi();
	for(int i=1;i<=n;i++) a[i]=rdll(),sum+=a[i];
	sort(a+1,a+n+1);
	m=rdi();
	for(int i=1;i<=m;i++){
		ll x=rdll(),y=rdll(),ans=INF;
		int pos=lower_bound(a+1,a+n+1,x)-a;
		if(pos<=n){
			ans=min(ans,max(y-(sum-a[pos]),0ll));
		}
		pos=upper_bound(a+1,a+n+1,x)-a-1;
		if(pos){
			ans=min(ans,(x-a[pos])+max(y-(sum-a[pos]),0ll));
		}
		printf("%lld\n",ans);
	}
    return 0;
}