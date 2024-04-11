#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<ll,bool> Node;

const int N=500010;

int n,k,a[N],b[N];

ll sum;
int calc(int mid){
    priority_queue<Node,vector<Node>,greater<Node>> q;
    int cnt=0;sum=0;
    for(int i=1;i<=n;i++){
        q.push({a[i],1});

        auto now=q.top();
        ll val=now.fi+b[i]-mid;
        if(val>=0) continue;
        q.pop(),cnt+=now.se,sum+=val;
        q.push({-b[i]+mid,0});
    }
    return cnt;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) b[i]=rdi();
    ll l=0,r=*max_element(a+1,a+n+1)+*max_element(b+1,b+n+1);
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(calc(mid)<=k) l=mid;
        else r=mid-1;
    }
    calc(l);
    ll ans=sum+k*l;
    cout<<ans<<endl;
    return 0;
}