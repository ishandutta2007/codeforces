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
#define taskname "E"
int n;
ll k;
ll a[100];
using matrix=ll[100][100];
const ll base=1000000007;
matrix core;
void multi(const matrix &A, const matrix &B, matrix &C){
    FFOR(i, 0, n) FFOR(j, 0, n){
        C[i][j]=0;
        FFOR(k, 0, n) C[i][j]+=(A[i][k]*B[k][j])%base;
        C[i][j]%=base;
    }
}
void power(const matrix &A, ll k, matrix &ans){
    matrix temp;
    FFOR(i, 0, n) FFOR(j, 0, n) ans[i][j]=A[i][j];
    DFOR(i, __lg(k)-1, 0){
        multi(ans, ans, temp);
        if(bit(k, i)) multi(temp, A, ans);
        else{
            FFOR(i, 0, n) FFOR(j, 0, n) ans[i][j]=temp[i][j];
        }
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    if(k==1){
        writeln(n);
        return 0;
    }
    FFOR(i, 0, n) read(a[i]);
    FFOR(i, 0, n) FFOR(j, 0, n) if((builtin_popcount(a[i]^a[j])%3)==0) core[i][j]=1;
    matrix ans;
    power(core, k-1, ans);
    ll res=0;
    FFOR(i, 0, n) FFOR(j, 0, n) res+=ans[i][j];
    res%=base;
    writeln(res);
}