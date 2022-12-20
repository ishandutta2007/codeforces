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

const int N=400010;
const ll INFl=0x3f3f3f3f3f3f3f3f;

ll n,m,k,a[N];
int T;

int tot;
pair<ll,ll> seq[N];

void solve(){
    n=rdll(),m=rdi(),k=rdll();
    for(int i=1;i<=m;i++) a[i]=rdll();
    a[0]=0,a[++m]=n,k+=m;
    for(int i=m;i>=1;i--) a[i]=a[i]-a[i-1];

    ll L,R;

    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r+1)/2;
        ll sum=0;
        for(int i=1;i<=m;i++) sum+=a[i]/mid;
        if(sum>=k) l=mid;
        else r=mid-1;
    }
    L=l;

    l=1,r=n;
    while(l<r){
        ll mid=(l+r)/2;
        ll sum=0;
        for(int i=1;i<=m;i++) sum+=(a[i]+mid-1)/mid;
        if(sum<=k) r=mid;
        else l=mid+1;
    }
    R=l;

    tot=0;
    for(int i=1;i<=m;i++){
        ll dl=a[i]/L,dr=(a[i]+R-1)/R;
        if(dr<=dl) continue;

        ll nxtL=min(L,a[i]/(dl+1));
        ll nxtR=dr>1?max(R,(a[i]+dr-2)/(dr-1)):INFl;
        seq[++tot]={nxtL,nxtR};
    }
    seq[++tot]={L,R};
    sort(seq+1,seq+tot+1);
    ll ans=n,mx=R;
    for(int i=1;i<=tot;i++){
        ans=min(ans,mx-seq[i].fi);
        mx=max(mx,seq[i].se);
    }
    cout<<ans<<'\n';
}

int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}