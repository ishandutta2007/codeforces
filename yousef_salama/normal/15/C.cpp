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
using namespace std;
int n;
long long x[100005], m[100005];
long long f(long long x){
    long long cur = (x + 1) / 2, ans = 0;

    if(cur % 2 != 0)ans = 1;

    if((x + 1) % 2 != 0)ans ^= x;
    return ans;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> m[i];

    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans ^= f(x[i] - 1) ^ f(x[i] + m[i] - 1);
    if(ans != 0)cout << "tolik" << endl;
    else cout << "bolik" << endl;
    return 0;
}