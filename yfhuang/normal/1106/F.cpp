#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int k;
const int maxk = 105;
int b[maxk];
int n, m;
const int mod = 998244353;
const int mod1 = mod - 1;
void upd(int &a ,int b, int M){
    a += b;
    if(a >= M)
        a -= M;
}

struct mat{
    int a[maxk][maxk];
    mat(){
        memset(a, 0, sizeof(a));
    }
    mat operator * (const mat b) const{
        mat c;
        for(int i = 0;i < k;i++){
            for(int j = 0;j < k;j++){
                for(int l = 0;l < k;l++){
                    upd(c.a[i][l], (int)(1LL * a[i][j] * b.a[j][l] % mod1), mod1);
                }
            }
        }
        return c;
    }
};

mat power(mat a, int n){
    mat I;
    for(int i = 0;i < k;i++){
        I.a[i][i] = 1;
    }
    while(n > 0){
        if(n & 1)
            I = (a * I);
        a = (a * a);
        n >>= 1;
    }
    return I;
}

int qpow(int a, int b, int mod){
    int ret = 1;
    while(b > 0){
        if(b & 1) ret = 1LL * ret * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ret;
}

int bsgs(int a, int b, int p){
    int m = ceil(sqrt(p));
    map<int, int> mp;
    int tmp = 1;
    mp[tmp] = 0;
    for(int i = 1;i < m;i++){
        tmp = 1LL * tmp * a % p;
        mp[tmp] = i;
    }
    int ni = qpow(a, m, p);
    ni = qpow(ni, p - 2, p);
    int now = b;
    for(int i = 0;i <= m;i++){
        if(mp.count(now)){
            return (1LL * mp[now] + 1LL * m * i) % (p - 1);
        }
        now = 1LL * now * ni % p;
    }
    return -1;
}

typedef long long LL;

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
    if(!b){d = a;x = 1;y = 0;}
    else{gcd(b, a%b, d, y, x);y -= 1LL * x * (a/b);}
}

LL gcd(LL a, LL b){
    return b == 0 ? a: gcd(b, a % b);
}

int main(){
    while(cin >> k){
        for(int i = 0;i < k;i++){
            cin >> b[i];
        }
        cin >> n >> m;
        mat a;
        for(int i = 1;i < k;i++){
            a.a[i][i - 1] = 1;
        }
        for(int j = 0;j < k;j++){
            a.a[0][j] = b[j];
        }
        a = power(a, n - k);
        int pw = a.a[0][0];
        int pw1 = bsgs(3, m, mod);
        LL g = gcd(1LL * pw, 1LL * mod1);
        if(pw1 % g)
            cout << -1 << endl;
        else{
            LL d, x, y;
            LL A, B;
            A = pw / g;
            B = mod1 / g;
            pw1 /= g;
            gcd(A, B, d, x, y);
            x *= pw1;
            y *= pw1;
            x = ((x % B) + B) % B; 
            cout << qpow(3, (int)x, mod) << endl;
        }
    }    
    return 0;
}