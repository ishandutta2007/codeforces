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

const int N=100010;
int n,m,a[N],s[N];

int sum[N];
void add(int x,int val){
	for(;x<=n*m;x+=(x&(-x))) sum[x]+=val;
}

int query(int x){
	int s=0;
	for(;x;x-=(x&(-x))) s+=sum[x];
	return s;
}

void solve(){
	n=rdi(),m=rdi();
	for(int i=1;i<=n*m;i++) a[i]=rdi(),s[i]=i,sum[i]=0;
	sort(s+1,s+n*m+1,[&](int x,int y){
		if(a[x]==a[y]) return x>y;
		else return a[x]<a[y];
	});
	ll ans=0;
	for(int i=1;i<=n*m;i++) ans+=query(s[i]),add(s[i],1);
	printf("%lld\n",ans);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}