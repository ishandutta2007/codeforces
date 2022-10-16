#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using ld=long double;
#define taskname "F"
#define left Kafuu
#define right Chino
int n;
int a[1000001];
int left[3000000];
pair <int, int> right[3000000];
vector <int> pos;
vector <int> allmask;
int now;
void push(pair <int, int> &p, int x){///get max the min
    if(x>p.first){
        p.second=p.first;
        p.first=x;
    }
    else if(x<p.first) p.second=max(p.second, x);
}
bool check(int x){
    now=x;
    pos.clear();
    allmask.clear();
    for(int b=20; b>=0; b--) if(x&(1<<b)) pos.pb(b);
    for(int a=x; a>0; a=(a-1)&x) allmask.pb(a);
    allmask.pb(0);
    reverse(allmask.begin(), allmask.end());
    for(int a: allmask) left[a]=n;
    for(int a: allmask) right[a]=mp(0, 0);
    left[0]=1;
    right[0]=mp(n, n-1);
    for(int i=1; i<=n; i++) if(left[a[i]&x]==n){
        left[a[i]&x]=i;
    }
    for(int i=n; i>=1; i--){
        push(right[a[i]&x], i);
    }
    ///SOS
    for(int i: pos){
        for(int a: allmask) if(a&(1<<i)){
            int u=a^(1<<i);
            push(right[u], right[a].first);
            push(right[u], right[a].second);
        }
    }
    for(int a: allmask){
        int b=x^a;
        if(left[a]<right[b].second) return 1;
    }
    return 0;
}
int main(){
    ///fuckme
    #ifdef Aria
        freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int ans=0;
    for(int b=20; b>=0; b--){
        ans^=1<<b;
        if(!check(ans)) ans^=1<<b;
    }
    cout<<ans;
}