#include <algorithm>
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
#define mp make_pair
#define pb push_back

const int N=300010;
int n,a[N],cnt[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    if(*max_element(cnt+1,cnt+n+1)>(n+1)/2) return (void)puts("-1");

    for(int i=1;i<=n;i++) cnt[i]=0;
    int k=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]) k++,cnt[a[i]]+=2;
    }
    cnt[a[1]]++,cnt[a[n]]++;
    printf("%d\n",k+max(0,*max_element(cnt+1,cnt+n+1)-k-2));
}

int T;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    T=rdi();
    while(T--) solve();
    return 0; 
}