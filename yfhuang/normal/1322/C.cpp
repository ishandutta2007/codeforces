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
#include <chrono>
#include <random>
#include <ctime>
using namespace std;

mt19937_64 rng;

int t;
int n, m;
const int maxn = 5e5 + 5;

typedef unsigned long long ull;
typedef long long LL;
ull hash1[maxn], hash2[maxn];
typedef pair<ull, ull> pii;

ull p[maxn];

bool cmp(int i, int j){
    return p[i] < p[j];
}

int id[maxn];
LL c[maxn];

LL gcd(LL a, LL b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    //rng = mt19937_64(chrono::high_resolution_clock().now().time_since_epoch().count());
    srand(time(0));
    cin >> t;
    for(int i = 1;i < maxn;i++){
            hash1[i] = 1LL * rand() * rand() * rand() * rand();
            //hash2[i] = static_cast<ull>(rng()); 
            if(hash1[i] == 0)
                hash1[i] = i;
    }
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n;i++){
            //p[i].first = p[i].second = 0;
            p[i] = 0;
            scanf("%lld", c + i);
        }
        for(int i = 1;i <= m;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            p[v] ^= hash1[u];
            //p[v].first ^= hash1[u];
            //p[v].second ^= hash2[u];
        }
        for(int i = 1;i <= n;i++){
            id[i] = i; 
        }
        sort(id + 1,id + 1 + n, cmp);
        LL ans = 0;
        LL sum = 0;
        for(int i = 1;i <= n;i++){
            //cout << p[id[i]].first << " " << p[id[i]].second << endl;
            sum += c[id[i]];
            if(i == n || p[id[i]] != p[id[i + 1]]){
                //if(p[id[i]].first and p[id[i]].second){
                if(p[id[i]]){
                    ans = gcd(ans, sum);
                }
                sum = 0;
            }
        }
        //cout << ans << endl;
        printf("%lld\n", ans);
    }
    return 0;
}