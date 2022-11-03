#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>
using namespace std;

const int maxn = 100 + 5;

long long n,m;
const long long mod = 1e9 + 7;
int k;

long long qpow(long long a,long long n){
    long long ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    if(k == -1){
        if((n + m) & 1){
            cout << 0 << endl;
        }else{

            cout << qpow(2,((n - 1) % (mod - 1)) * ((m - 1) % (mod - 1)) % (mod - 1)) << endl;
        }
    }else{
            cout << qpow(2,((n - 1) % (mod - 1)) * ((m - 1) % (mod - 1)) % (mod - 1)) << endl;
    }
    return 0;
}