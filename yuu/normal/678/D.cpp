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
#define taskname "D"
const ll base=1000000007;
using matrix=ll[2][2];
void multi(const matrix &A, const matrix &B, matrix &C){
    FFOR(i, 0, 2) FFOR(j, 0, 2){
        C[i][j]=0;
        FFOR(k, 0, 2) C[i][j]+=A[i][k]*B[k][j];
        C[i][j]%=base;
    }
}
void power(const matrix &A, ll x, matrix &ans){
    matrix temp;
    FFOR(i, 0, 2) FFOR(j, 0, 2) ans[i][j]=A[i][j];
    DFOR(i, __lg(x)-1, 0){
        multi(ans, ans, temp);
        if(bit(x, i)) multi(temp, A, ans);
        else{
            FFOR(i, 0, 2) FFOR(j, 0, 2) ans[i][j]=temp[i][j];
        }
    }
}
matrix core, res;
ll a, b, n, x;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(a);
    read(b);
    read(n);
    read(x);
    core[0][0]=a;
    core[0][1]=b;
    core[1][1]=1;
    power(core, n, res);
    a=res[0][0];
    b=res[0][1];
    writeln((a*x+b)%base);
}