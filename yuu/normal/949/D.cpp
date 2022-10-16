#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, d;
ll b;
ll a[100001];
deque <pair <ll, ll>> s;
bool check(ll m){
    s.clear();
    for(int i=1; i<=n; i++) if(a[i]) s.push_back({i, a[i]});
    int l=1+m, r=n-m;
    ll dist=(m+1)*d;
    while(l<=r){
        while((!s.empty())&&(s.front().first+dist<l)) s.pop_front();
        while((!s.empty())&&(s.back().first-dist>r)) s.pop_back();
        ll remain=b;
        ll use;
        while((!s.empty())&&remain){
            if(s.front().first-dist>l) return 0;
            use=min(s.front().second, remain);
            remain-=use;
            s.front().second-=use;
            if(s.front().second==0) s.pop_front();
        }
        if(remain) return 0;
        if(l<r){
            remain=b;
            while((!s.empty())&&remain){
                if(s.back().first+dist<r) return 0;
                use=min(s.back().second, remain);
                remain-=use;
                s.back().second-=use;
                if(s.back().second==0) s.pop_back();
            }
            if(remain) return 0;
        }
        l++;
        r--;
        dist+=d;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>d>>b;
    for(int i=1; i<=n; i++) cin>>a[i];
    check(1);
    ll ans=n/2;
    ll l=0, r=ans-1, m;
    while(l<=r){
        m=(l+r)/2;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout<<ans<<'\n';
}