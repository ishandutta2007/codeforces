#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "E"
ll n, m;
ll a[36];
ll ans=0;
void backtrack0(int u, ll s){
    if(u>n) ans=max(ans, s);
    else{
        backtrack0(u+1, s);
        backtrack0(u+1, (s+a[u])%m);
    }
}
set <ll> S;
void backtrack1(int u, ll s){
    if(u>20) S.insert(s);
    else{
        backtrack1(u+1, s);
        backtrack1(u+1, (s+a[u])%m);
    }
}
void backtrack2(int u, ll s){
    if(u>n){
        set <ll>::iterator it=S.lower_bound(m-s);
        if(it!=S.begin()){
            it--;
            ans=max(ans, s+*it);
        }
        ans=max(ans, (s+*S.rbegin())%m);
    }
    else{
        backtrack2(u+1, s);
        backtrack2(u+1, (s+a[u])%m);
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FOR(i, 1, n) read(a[i]);
    if(n<=20) backtrack0(1, 0);
    else{
        backtrack1(1, 0);
        backtrack2(21, 0);
    }
    writeln(ans);
}