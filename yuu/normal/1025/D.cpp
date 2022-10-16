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
#define taskname "D"
#define left Teion
#define right Hozon
int n;
ll a[701];
vector <int> left[701];
vector <int> right[701];
bool f[701][701][2];
bool done[701][701][2];
bool F(int l, int r, bool ir){
    if(done[l][r][ir]) return f[l][r][ir];
    done[l][r][ir]=1;
    if(ir){
        if(l==r) return f[l][r][ir]=__gcd(a[r], a[r+1])>1;
        else{
            for(int i: left[r+1]){
                if(i<l) break;
                if(i==l){
                    if(F(l+1, r, 0)) return f[l][r][ir]=1;
                }
                else if(i==r){
                    if(F(l, r-1, 1)) return f[l][r][ir]=1;
                }
                else{
                    if(F(l, i-1, 1)&&F(i+1, r, 0)) return f[l][r][ir]=1;
                }
            }
        }
    }
    else{
        if(l==r) return f[l][r][ir]=__gcd(a[l], a[l-1])>1;
        else{
            for(int i: right[l-1]){
                if(i>r) break;
                if(i==l){
                    if(F(l+1, r, 0)) return f[l][r][ir]=1;
                }
                else if(i==r){
                    if(F(l, r-1, 1)) return f[l][r][ir]=1;
                }
                else{
                    if(F(l, i-1, 1)&&F(i+1, r, 0)) return f[l][r][ir]=1;
                }
            }
        }
    }
    return f[l][r][ir]=0;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n){
        DFOR(j, i-1, 1) if(__gcd(a[i], a[j])>1) left[i].pb(j);
        FOR(j, i+1, n) if(__gcd(a[i], a[j])>1) right[i].pb(j);
    }
    if(F(2, n, 0)||F(1, n-1, 1)) puts("Yes");
    else{
        FFOR(i, 2, n) if(F(1, i-1, 1)&&F(i+1, n, 0)){
            puts("Yes");
            return 0;
        }
        puts("No");
    }
}