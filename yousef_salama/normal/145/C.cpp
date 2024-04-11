#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define MOD 1000000007
using namespace std;
int n, k, a[100005], cnt[1050], lucky[1050], un = 0;
long long dp[1050][1050];
map <int, int> mp;
long long Power(long long number, long long exponent, long long ivalue) {
    long long ret = 1;
    long long multiplier = number;
    while(exponent > 0LL){
            if(exponent % 2LL)
                ret = (ret * multiplier) % ivalue;
            exponent /= 2LL;
            multiplier = (multiplier * multiplier) % ivalue;
    }
    return ret;
}

long long MultiplicativeInverse(long long number, long long ivalue) {
    return Power(number, ivalue - 2LL, ivalue);
}
long long FastCombination(long long from, long long pick, long long ivalue, bool reset = false) {
  static vector<long long> fact, rfact;
  if(reset)fact = rfact = vector<long long>(0);
  if(fact.size() == 0LL){
    fact.push_back(1LL);
    rfact.push_back(1LL);
  }
  if(pick > from)return 0LL;
  long long table_size = max(from, max(pick, from-pick));
  while(fact.size() <= table_size){
    fact.push_back((fact.back() * (long long)(fact.size())) % ivalue);
    rfact.push_back(MultiplicativeInverse(fact.back(), ivalue));
  }
  long long res = (fact[from] * rfact[pick]) % ivalue;
  return (res * rfact[from - pick]) % ivalue;
}
void dfs(long long i){
    if(i > 1000000000LL)return;
    mp[i] = mp.size();
    lucky[mp.size() - 1] = i;
    dfs(i * 10 + 4); dfs(i * 10 + 7);
}
int main(){
    scanf("%d %d", &n, &k);
    dfs(4); dfs(7);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(mp.count(a[i]))cnt[mp[a[i]]]++;
        else un++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= mp.size(); i++){
        long long a = cnt[mp[lucky[i - 1]]];
        for(int rem = 0; rem <= mp.size(); rem++)
            dp[i][rem] = (dp[i - 1][rem] + (rem - 1 >= 0?dp[i - 1][rem - 1]:0) * a) % MOD;
    }
    long long res = 0;
    for(int i = 0; i <= mp.size(); i++){
        if(k - i <= un && k >= i){
            res += (dp[mp.size()][i] * FastCombination(un, k - i, MOD)) % MOD;
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}