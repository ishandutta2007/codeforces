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

const int N=200010;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n;
struct Seg{int l,r;ll c;}s[N];

void solve(){
    n=rdi();
    int l=1e9,r=-1e9;
    ll cl=INF,cr=INF,ci=INF;
    for(int i=1;i<=n;i++){
        s[i].l=rdi(),s[i].r=rdi(),s[i].c=rdi();
        
        if(s[i].l<l) cl=s[i].c,ci=INF;
        else if(s[i].l==l) cl=min(cl,s[i].c);
        if(s[i].r>r) cr=s[i].c,ci=INF;
        else if(s[i].r==r) cr=min(cr,s[i].c);
        
        if(s[i].l<=l&&s[i].r>=r){
            if(s[i].l==l&&s[i].r==r) ci=min(ci,s[i].c);
            else ci=s[i].c;
        }
            
        l=min(l,s[i].l),r=max(r,s[i].r);
        
        ll sum=min(cl+cr,ci);
        cout<<sum<<'\n';
    }
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}