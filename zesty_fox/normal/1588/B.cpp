#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

ll query(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    return rdll();
}

void print_ans(int i,int j,int k){
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    return;
}

int n;

ll istriangle(ll x){
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(mid*(mid-1)/2<=x) l=mid;
        else r=mid-1;
    }
    if(l*(l-1)/2==x) return l;
    else return 0;
}

void solve(){
    n=rdi();
    ll sum=query(1,n);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(query(mid,r)) l=mid+1;
        else r=mid;
    }
    ll now=query(1,l),now1=query(1,l-1);
    int j=l-(now-now1);
    int i=j-istriangle(sum-query(j,n));
    print_ans(i,j,l);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}