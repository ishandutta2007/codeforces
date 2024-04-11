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
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "D2"
const ll base=998244353;
int n;
int a[100001];
int cnt[11];
int get_length(int a){
    int ans=0;
    while(a>0){
        ans++;
        a/=10;
    }
    return ans;
}
ll get(int a){
    ll ans=0;
    vector <int> digits;
    while(a>0){
        digits.pb(a%10);
        a/=10;
    }
    int l=digits.size();
    ///f(a, ...)
    FOR(i, 1, l){
        ///i <= l
        ll p10=cnt[i];
        int c=i;
        int now=0;
        FFOR(j, 0, i+l){
            if(j%2==0){
                if(c) c--;
                else{
                    ans=(ans+p10*digits[now])%base;
                    now++;
                }
            }
            else{
                ans=(ans+p10*digits[now])%base;
                now++;
            }
            p10=(p10*10)%base;
        }
    }
    FOR(i, l+1, 10){
        ///i <= l
        ll p10=cnt[i];
        int c=i;
        int now=0;
        FFOR(j, 0, i+l){
            if(j%2==0){
            }
            else{
                ans=(ans+p10*digits[now])%base;
                now++;
                if(now==digits.size()) break;
            }
            p10=(p10*10)%base;
        }
    }
    ///f(..., a)
    FFOR(i, 1, l){
        ///i < l
        ll p10=cnt[i];
        int c=i;
        int now=0;
        FFOR(j, 0, i+l){
            if(j%2==0){
                ans=(ans+p10*digits[now])%base;
                now++;
            }
            else{
                if(c) c--;
                else{
                    ans=(ans+p10*digits[now])%base;
                    now++;
                }
            }
            p10=(p10*10)%base;
        }
    }
    FOR(i, l, 10){
        ///i>=l
        ll p10=cnt[i];
        int c=i;
        int now=0;
        FFOR(j, 0, i+l){
            if(j%2==0){
                ans=(ans+p10*digits[now])%base;
                now++;
                if(now==digits.size()) break;
            }
            else{
            }
            p10=(p10*10)%base;
        }
    }
    return ans;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) cnt[get_length(a[i])]++;
    ll ans=0;
    FOR(i, 1, n) ans+=get(a[i]);
    ans%=base;
    writeln(ans);
}