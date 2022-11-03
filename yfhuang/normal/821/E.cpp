#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 105;

int n;
long long k;
long long a[maxn],b[maxn];
int c[maxn];

const long long mod = 1e9 + 7;
typedef long long LL;
typedef vector<long long> vec;
typedef vector<vec> mat;

mat mul(mat a,mat b){
    mat c(a.size(),vec(b[0].size()));
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++){
            for(int k = 0;k < b[0].size();k++){
                c[i][k] = (c[i][k] + a[i][j] * b[j][k] % mod + mod) % mod;
            }
        }
    }
    return c;
}

mat power(mat a,long long n){
    mat b(a.size(),vec(a.size()));
    for(int i = 0;i < b.size();i++){
        b[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) b = mul(b,a);
        a = mul(a,a);
        n >>= 1;
    }
    return b;
}

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld%d",&a[i],&b[i],&c[i]);
    }
    b[n] = min(b[n],k);
    mat A(1,vec(16));
    A[0][0] = 1;
    for(int i = 1;i <= 15;i++) A[0][i] = 0;
    for(int i = 1;i <= n;i++){
        mat B(c[i] + 1,vec(c[i] + 1));
        for(int j = 0;j <= c[i];j++){
            for(int k = 0;k <= c[i];k++){
                B[j][k] = 0;
            }
        }
        if(A[0].size() > c[i] + 1){mat tmp = A;
        A = mat(1,vec(c[i] + 1));
        for(int j = 0;j <= c[i];j++){
            A[0][j] = tmp[0][j];
        }}
        else{
            int x = A[0].size();
            for(int j = x + 1;j <= c[i] + 1;j++){
                A[0].push_back(0);
            }
        }
        for(int j = 0;j <= c[i];j++){
            if(j - 1 >= 0){
                B[j][j - 1] = 1;
            }B[j][j] = 1;
            if(j + 1 <= c[i]) B[j][j + 1] = 1;
        }
        mat C = power(B,1LL * b[i] - 1LL * a[i]);
//        for(int j = 0;j < C.size();j++){
//            for(int k = 0;k < C[0].size();k++){
//                cout << C[j][k] << " ";
//            }
//            cout << endl;
//        }
//        for(int j = 0;j < A[0].size();j++){
//            cout << A[0][j] << " " ;
//        }
        A = mul(A,C);
       // cout << A[0][0] << endl;
        
    }
    cout << A[0][0] << endl;
    return 0;
}

/*
 5 4 3
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 2 3 4
 2 3 1 2
 3 4 3 4
*/