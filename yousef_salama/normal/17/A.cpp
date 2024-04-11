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
#define oo 1 << 25
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> primes;
    bool v[n + 1];
    memset(v, 0, sizeof v);
    for(int i = 2; i <= n; i++)if(!v[i]){
        primes.push_back(i);
        for(int j = i + i; j <= n; j += i)
            v[j] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < primes.size(); i++)
        for(int j = 0; j < primes.size() - 1; j++)if(j != i){
            if(primes[j] + primes[j + 1] + 1 == primes[i]){
                cnt++;
                break;
            }
        }
    if(cnt >= k)printf("YES\n");
    else printf("NO\n");
    return 0;
}