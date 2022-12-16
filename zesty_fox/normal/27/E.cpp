#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int INF=0x3f3f3f3f;
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n;ll ans;
void dfs(int dep,int cnt,ll num,int lim){
    if(cnt>n||dep>=16) return;
    if(cnt==n){
        ans=min(ans,num);
        return;
    }
    ll p=pr[dep],mul=pr[dep];
    for(int i=1;i<=min(lim,63);i++,mul*=p){
        if(num*mul>=ans) break;
        dfs(dep+1,cnt*(i+1),num*mul,i);
    }
}

int main(){
    n=rdi();ans=1e18;
    dfs(0,1,1,63);
    printf("%lld\n",ans);
    return 0;
}