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
int n, m, k, p[2005];
int findr(int i, int p[]){
    if(i == p[i])return i;
    else return p[i] = findr(p[i], p);
}
void Union(int i, int j, int p[]){
    p[findr(i, p)] = findr(j, p);
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        p[i] = i;
    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j < k; j++){
            int l = k - j - 1;
            Union(j + i, l + i, p);
        }
    }
    set <int> s;
    for(int i = 0; i < n; i++)
        s.insert(findr(i, p));
    long long ans = 1;
    for(int i = 0; i < s.size(); i++){
        ans *= m;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}