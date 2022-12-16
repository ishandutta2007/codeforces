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

const int N=100010,M=310;
int n,m,a[N],s[N],p[N];

int sum[M][N];
void add(int id,int x,int val){
	for(;x<=n*m;x+=(x&(-x))) sum[id][x]+=val;
}

int query(int id,int x){
	int s=0;
	for(;x;x-=(x&(-x))) s+=sum[id][x];
	return s;
}

void solve(){
	n=rdi(),m=rdi();
	for(int i=1;i<=n*m;i++) a[i]=rdi(),s[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n*m;j++) sum[i][j]=0;
	sort(s+1,s+n*m+1,[&](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;});
	for(int i=1;i<=n*m;i++){
		int now=i;
		while(now<=n*m&&a[s[i]]==a[s[now]]) now++;
		now--;
		for(int j=(i-1)/m+1;j<=(now-1)/m+1;j++){
			sort(s+max((j-1)*m+1,i),s+min(j*m,now)+1,[&](int x,int y){return x>y;});
		}
		i=now;
	}
	ll ans=0;
	for(int i=1;i<=n*m;i++) ans+=query((i-1)/m+1,s[i]),add((i-1)/m+1,s[i],1);
	printf("%lld\n",ans);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}