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
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "D"
ll a, b, m;
int test(ll a, ll b, ll m, ll sum){
    ll low=a, high=a;
    ll sum_low=sum, sum_high=sum;
    int cnt=0;
    while(true){
        cnt++;
//        cerr<<low<<' '<<high<<'\n';
        if(low<=b&&high>=b) return cnt;
        if(low>b) return 0;
        low=sum_low+1;
        sum_low=sum_low+low;
        high=sum_high+m;
        sum_high=sum_high+high;
    }
}
bool test_less(ll a, ll b, ll first, ll sum, int turn){
    ll low=a;
    ll sum_low=sum;
    FOR(i, 1, turn){
        low=sum_low+((i==1)?first:1);
        sum_low=sum_low+low;
    }
    return (low<=b);
}
void solve(){
    read(a);
    read(b);
    read(m);
    int turncnt=0;
    if((turncnt=test(a, b, m, a))==0) puts("-1");
    else{
        vector <ll> ans;
        ans.pb(a);
        ll sum=a;
        while(a!=b){
            turncnt--;
            if(turncnt<1) break;
            ll low=1, high=m, mid, res=0;
            while(low<=high){
                mid=(low+high)/2;
                if(test_less(a, b, mid, sum, turncnt)){
                    res=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            a=sum+res;
            ans.pb(a);
            sum+=a;
        }
        write(ans.size());
        for(auto x: ans){
            putchar(' ');
            write(x);
        }
        putchar('\n');
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int q;
    read(q);
    while(q--) solve();
}
/// x[i]=f[i-1]+r[i]
/// f[i]=f[i-1]*2+r[i]
///