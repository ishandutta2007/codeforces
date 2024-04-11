#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "B"
ll x, y, l, r;
vector <ll> v;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(x);
    read(y);
    read(l);
    read(r);
    ll px=1;
    while(true){
        ll py=1;
        while(true){
            if(px+py<=r&&px+py>=l) v.pb(px+py);
            if(log10(py)+log10(y)>18) break;
            py*=y;
            if(py>r) break;
        }
        if(log10(px)+log10(x)>18) break;
        px*=x;
        if(px>r) break;
    }
    v.pb(l-1);
    v.pb(r+1);
    sort(v.begin(), v.end());
    ll ans=0;
    for(int i=1; i<v.size(); i++) ans=max(ans, v[i]-v[i-1]-1);
    writeln(ans);
}