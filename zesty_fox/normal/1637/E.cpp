#include <algorithm>
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

const int N=300010;

int n,m,a[N];
vi v[N];

vi lsh;
void discrete(){
    lsh.clear();
    for(int i=1;i<=n;i++) lsh.pb(a[i]);
    sort(lsh.begin(),lsh.end());lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
}

bool banned(const vector<pii> &ban,pii x){
    if(x.fi==x.se) return true;
    auto it=lower_bound(ban.begin(),ban.end(),x);
    if(it!=ban.end()&&(*it)==x) return true;
    return false;
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();

    map<int,int> m1;
    vector<pii> cnt;
    for(int i=1;i<=n;i++) m1[a[i]]++;
    for(auto tmp:m1) cnt.pb(tmp);

    vector<pii> ban;
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        if(x>y) swap(x,y);
        ban.pb({x,y}),ban.pb({y,x});
    }
    sort(ban.begin(),ban.end());

    ll ans=0;
    if(cnt.size()<=1000){
        for(auto t1:cnt){
            for(auto t2:cnt){
                if(t1>=t2) continue;
                if(banned(ban,{t1.fi,t2.fi})) continue;
                ans=max(ans,(ll)(t1.fi+t2.fi)*(t1.se+t2.se));
            }
        }
    }
    else{
        for(int i=1;i<=n;i++) v[i].clear();
        for(auto tmp:cnt) v[tmp.se].pb(tmp.fi);

        vi seq;
        for(int i=1;i<=n;i++) 
            if(!v[i].empty()) seq.pb(i),sort(v[i].begin(),v[i].end());

        for(auto x:seq){
            for(auto y:seq){
                if(x>y) continue;
                for(auto v1:v[x]){
                    for(auto it=v[y].rbegin();it!=v[y].rend();it++){
                        if(banned(ban,{v1,*it})) continue;
                        else {ans=max(ans,(ll)(x+y)*(v1+(*it)));break;}
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}