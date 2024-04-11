#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

const int maxn = 1e5 + 5;
bool isprime[maxn];
vector<int> primes;

void init(){
    isprime[1] = true;
    for(int i = 2;i < maxn;i++){
        if(!isprime[i]){
            for(int j = i * 2;j < maxn;j += i){
                isprime[j] = true;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int id = lower_bound(primes.begin(), primes.end(), 1 + d) - primes.begin();
        int val = primes[id];
        int id1 = lower_bound(primes.begin(), primes.end(), val + d) - primes.begin();
        int val1 = primes[id1];
        cout << 1LL * val * val1 << endl;
    }
    return 0;
}