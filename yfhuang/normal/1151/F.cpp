#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, k;

typedef long long LL;

const LL mod = 1e9 + 7;

LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

struct matrix{
    int n;
    LL a[105][105];
    matrix(int _n = 0):n(_n){
        memset(a, 0, sizeof(a));
    }
    matrix operator * (matrix rhs){
        matrix c(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(a[i][j] == 0) continue;
                for(int k = 0;k < n;k++){
                    c.a[i][k] = (c.a[i][k] + a[i][j] * rhs.a[j][k]) % mod;
                }
            }
        }
        return c;
    }
};

matrix qpow(matrix a, int n){
    matrix c(a.n);
    for(int i = 0;i < a.n;i++){
        c.a[i][i] = 1;
    }
    while(n > 0){
        if(n & 1){
            c = c * a; 
        }
        a = a * a;
        n >>= 1;
    }
    return c;
}

int a[105];
int b[105];
int main(){
    while(cin >> n >> k){
        int cur = 0;
        for(int i = 0;i < n;i++){
            scanf("%d", &a[i]);
            if(a[i] == 0)
                cur++;
        }
        int st = 0;
        for(int i = 0;i < cur;i++){
            if(a[i] == 0)
                st++;
        }
        matrix m(cur + 1);
        for(int i = 0;i <= cur;i++){
           int cnt0 = cur - i, cnt1 = (n - cur) - cnt0;
           if(cnt0 < 0 || cnt1 < 0)
              continue; 
           memset(b, 0, sizeof(b));
           for(int j = i;j < cur;j++){
               b[j] = 1;
           }
           for(int j = cur + cnt0;j < n;j++){
                b[j] = 1;
           }
           LL inv = qpow(2, mod - 2);         
           LL p = n * (n - 1) % mod * inv % mod;
           p = qpow(p, mod - 2) % mod;
           for(int j = 0;j < n;j++){
               for(int k = j + 1;k < n;k++){
                    if(b[j] == b[k]){
                        m.a[i][i] = (m.a[i][i] + p) % mod;
                    }else{
                        if(j < cur && k >= cur){
                            if(b[j] == 0){
                                m.a[i - 1][i] = (m.a[i - 1][i] + p) % mod;
                            }else{
                                m.a[i + 1][i] = (m.a[i + 1][i] + p) % mod;
                            }
                        }else{
                            m.a[i][i] = (m.a[i][i] + p) % mod;
                        }
                    }
               }
           }
        }
        m = qpow(m, k);
        cout << m.a[cur][st] << endl;         
    } 
    return 0;
}