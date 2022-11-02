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
typedef pair < int , int > Point;

int MOD;
const int N = 2;
struct Matrix{
    int n,m;
    int a[N][N];
    Matrix() {}
    Matrix(int n ,int m) : n(n) , m(m) {
        memset(a,0,sizeof(a)); 
    }
    int* operator [] (const int x) {
        return a[x];
    }
    Matrix multiply(const Matrix& B) const {
        Matrix C(B.n , m);
        rep (r , B.n) rep (c , m) rep (id , n) (C[r][c] += a[id][c] * B.a[r][id]) %= MOD;
        return C;
    }
    Matrix pow(int ex) const {
        Matrix B = *this , Base = *this;
        ex--;
        while (ex) {
            if (ex & 1) B = B.multiply(Base);
            Base = Base.multiply(Base);
            ex >>= 1;
        }
        return B;
    }
};

int power(int base , int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) (res *= base) %= MOD;
        (base *=  base) %= MOD;
        exp >>= 1;
    }
    return res;
}

void solve(){
    int n , k , l;
    cin >> n >> k >> l >> MOD;
    Matrix A(2 , 1) , B(2 , 2);
    A[0][0] = 1 ; A[1][0] = 2;
    B[0][0] = 0 ; B[0][1] = B[1][0] = B[1][1] = 1;
    A = A.multiply (B.pow(n));
    int m0 = A[0][0];
    int m1 = power(2,n);
    m1 = (m1 - m0 + MOD + MOD) % MOD;
    if (k >> l) {
        puts("0");
        return;
    }
    int ans = 1;
    rep (i,l) (ans *= ( (k & (1LL << i)) ? m1 : m0 )) %= MOD;
    cout << ans % MOD << endl;
}

#undef int
int main(){
    solve();    
    return 0;
}