#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
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
ll n, k;
vector <ll> divisors;
vector <ll> ans;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    if(k>1000000){
        puts("-1");
        return 0;
    }
    FOR(i, 1, n){
        if(i*i>n) break;
        if(n%i==0){
            divisors.pb(i);
            divisors.pb(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    while(!divisors.empty()){
        if((n/divisors.back())<k*(k+1)/2) divisors.pop_back();
        else break;
    }
    if(divisors.empty()){
        puts("-1");
    }
    else{
        ll x=divisors.back();
        FOR(i, 1, k) ans.pb(i);
        ans.back()+=(n/x)-(k*(k+1)/2);
        for(ll a: ans){
            write(a*x);
            putchar(' ');
        }
    }
}