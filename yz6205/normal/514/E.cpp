#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define int long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 

const int MOD = (int)(1e9 + 7);
const int MK = 101;

struct Matrix{
    static const int N = MK;
    int a[N][N];
    int nr,nc;
    
    Matrix () { 
        memset(a,0,sizeof(a)); 
        nr = nc = 0;
    }
    
    int* operator [] (int x) {
        return a[x];
    }
    
    Matrix add(Matrix B){
        Matrix res;
        res.nr = nr;
        res.nc = nc;
        rep (i,nr) rep (j,nc) res[i][j] = (a[i][j] + B[i][j]) % MOD;
        return res;
    }

    Matrix multiply(Matrix B) {
        Matrix res;
        res.nr = B.nr;
        res.nc = nc;
        rep (i,B.nr) rep (j,nc) rep (k,nr) {
            (res[i][j] += a[k][j] * B[i][k]) %= MOD;
        }
        return res;
    } 

    void show(){
        rep(i,nr){
            rep(j,nc) cout << a[i][j] << ' ';
            puts("");
        }
    }
};

int n,x;
Matrix multiplier;

void init(){
    scanf("%lld%lld",&n,&x);
    rep (i,n) {
        int w;
        scanf("%lld",&w);
        multiplier[MK - 1][MK - w] ++;
        multiplier[MK - 1][MK - 1 - w] --;
    }  
    multiplier[MK - 1][MK - 1]++; 
    multiplier.nc = multiplier.nr = MK;
    rep (i,MK - 1) multiplier[i][i + 1] = 1;
}

Matrix power (int expon){
    Matrix res;
    res.nc = res.nr = MK;
    rep (i,MK) res[i][i] = 1;
    Matrix Base = multiplier;
    while (expon){
        if (expon & 1) res = res.multiply(Base);
        expon >>= 1;
        Base = Base.multiply(Base);
    }
    return res;
}

#undef int
int main(){
    init();
    Matrix ize; 
    ize.nr = MK;
    ize.nc = 1;
    ize[MK - 1][0] = 1;
    printf("%lld\n",ize.multiply(power(x))[MK - 1][0]);
    return 0;
}