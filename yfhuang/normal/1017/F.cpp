#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
#include <bitset>
using namespace std;

int n;
unsigned int A, B, C, D;
typedef long long LL;

unsigned int cal(int p){
    unsigned int val = A * p * p * p + B * p * p + C * p + D;
    unsigned int ret = 0;
    for(LL i = p; i <= n;i *= p){
        LL num = n / i;
        ret += val * num;
    }
    return ret;
}

const int maxn = 1e8 + 5;

bitset<maxn> prime;

void solve(){
    unsigned int ans = 0;
    ans += cal(2);
    ans += cal(3);
    for(LL i = 5, v = 2;i <= n;i += v, v = 6 - v)
        if(!prime[i / 3])
        {
            ans += cal(i);
            for(LL j = i * i, v1 = v;j <= n; j += v1 * i, v1 = 6 - v1){
            //for(LL j = i * i;j <= n;j += i){
                prime[j / 3] = 1; 
            }
        }
    cout << ans << endl;
}

int main(){
    cin >> n >> A >> B >> C >> D;
    solve();
    return 0;
}