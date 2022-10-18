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
    int N;
    cin >> N;
    int hash[21], a[N];
    memset(hash, 0, sizeof hash);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        hash[a[i] + 10]++;
    }
    long long ans = 0;
    for(int i = 0; i < N; i++){
        hash[a[i] + 10]--;
        ans += hash[-a[i] + 10];
    }
    cout << ans << endl;
    return 0;
}