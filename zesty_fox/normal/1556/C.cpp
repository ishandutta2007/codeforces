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

const int N=1010;
int n;
ll a[N],ans;
int main(){
	n=rdi();
	for(int i=1;i<=n;i++) a[i]=rdi();
	for(int l=1;l<=n;l+=2){
		ll sum=0,minx=1e18;
		for(int r=l+1;r<=n;r+=2){
			ll le=a[l],ri=a[r],L=max({-sum-le,-ri}),R=min({-sum+minx,-sum-1,-1ll});
			ans+=(R>=L?R-L+1:0);
			
			minx=min(minx,sum-a[r]);
			minx=min(minx,sum-a[r]+a[r+1]);
			sum+=a[r+1]-a[r];
		}
	}
	cout<<ans<<endl;
    return 0;
}