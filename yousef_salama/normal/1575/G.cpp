#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

int prime[MAXN], phi[MAXN];
vector <int> divisor[MAXN];

int main(){
    for(int i = 1; i < MAXN; i++)
    for(int j = i; j < MAXN; j += i)
        divisor[j].push_back(i);

    memset(prime, -1, sizeof prime);

    for(int i = 2; i < MAXN; i++){
        if(prime[i] != -1)continue;
        prime[i] = i;
        for(int j = 2 * i; j < MAXN; j += i)
            if(prime[j] == -1)prime[j] = i;
    }
    for(int i = 1; i < MAXN; i++){
        if(i == 1)phi[i] = 1;
        else{
            int p = prime[i];
            int j = i;
            while(j % p == 0)j /= p;
            
            if(j == 1)phi[i] = i - i / p;
            else phi[i] = phi[j] * phi[i / j];
        }
    }

    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long res = 0;
    for(int i = 1; i <= n; i++){
        if(n / i <= 300){
            long long cur = 0;
            for(int j = i - 1; j < n; j += i){
                cur = cur + a[j];
                for(int k = j + i; k < n; k += i){
                    cur = cur + __gcd(a[j], a[k]) * 2;
                }
            }
            res = (res + cur * phi[i]) % MOD;
        }else{
            vector <int> mp(MAXN, 0);
            for(int j = i - 1; j < n; j += i){
                for(int x : divisor[a[j]]){
                    mp[x]++;
                }
            }

            long long cur = 0;
            for(int j = 1; j < MAXN; j++)
                cur = (cur + 1LL * mp[j] * mp[j] * phi[j]) % MOD;
            res = (res + cur * phi[i]) % MOD;    
        }
    }
    printf("%lld\n", res);

    return 0;
}