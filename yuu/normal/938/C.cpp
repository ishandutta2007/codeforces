#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
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
ll x;
vector <pair <ll, int> > v;
void fact(ll n){
    v.clear();
    ll i=2;
    while(i*i<=n){
        if(n%i==0){
            v.pb(mp(i, 0));
            while(n%i==0){
                n/=i;
                v.back().second++;
            }
        }
        i++;
    }
    if(n>1) v.pb(mp(n, 1));
}
bool have_solution;
pair <ll, ll> ans;
void backtrack(int u, int a, ll s){
    if(have_solution) return;
    if(s*s>x) return;
    if(u==v.size()){
        ll b=x/s;
        if((s+b)%2) return;
        ll n=(s+b)/2;
        ll ndm=b-n;
        if(ndm<=0) return;
        ll lower_m=n/(ndm+1)+1;
        ll upper_m=n/ndm;
        lower_m=max(lower_m, 1LL);
        upper_m=min(upper_m, n);
        if(lower_m<=upper_m){
            have_solution=1;
            ans=mp(n, lower_m);
        }
    }
    else{
        backtrack(u+1, 0, s);
        if(a<v[u].second) backtrack(u, a+1, s*v[u].first);
    }
}
void solve(){
    read(x);
    if(x==0){
        puts("1 1");
        return;
    }
    fact(x);
    have_solution=0;
    backtrack(0, 0, 1);
    if(!have_solution){
        writeln(-1);
    }
    else{
        write(ans.first);
        putchar(' ');
        writeln(ans.second);
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    int t;
    read(t);
    while(t--) solve();
}