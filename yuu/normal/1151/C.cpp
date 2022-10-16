#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "C"
const ll base=1000000007;
vector <pair <ll, ll>> v;
ll l, r;
ll get_sum(ll start, ll cnt){
    if(start%2) return (cnt+get_sum(start-1, cnt))%base;
    else{
        start/=2;
        ll finish=start+cnt-1;
        start--;
        start%=base;
        if(start<0) start+=base;
        finish%=base;
        return (finish*(finish+1)-start*(start+1))%base;
    }
}
ll sum(ll x){
    if(x==0) return 0;
    ll res=0;
    for(auto p: v){
        if(p.second<x){
            x-=p.second;
            res=(res+get_sum(p.first, p.second))%base;
        }
        else{
            res=(res+get_sum(p.first, x))%base;
            return (res+base)%base;
        }
    }
    exit(-1);
    return 0;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(l);
    read(r);
    {
        ll sz=1;
        ll start_odd=1;
        ll start_even=2;
        ll sum_of_sz=0;
        while(sum_of_sz<1e18){
            sum_of_sz+=sz;
            v.pb(mp(start_odd, sz));
            start_odd+=sz*2;
            sz*=2;

            sum_of_sz+=sz;
            v.pb(mp(start_even, sz));
            start_even+=sz*2;
            sz*=2;
        }
        bug(sum_of_sz);
    }
    writeln((sum(r)+base-sum(l-1))%base);
}