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
int n, a[100005];
long long L[100005], R[100005];
int MaxEven(int val){
    if(val & 1)return val - 1;
    else return val;
}
int MaxOdd(int val){
    if(val & 1)return val;
    return val - 1;
}
int main(){
    cin >> n;
    for(int i = 0; i < (n - 1); i++)
        cin >> a[i];

    L[0] = 0;
    for(int i = 1; i < n; i++){
        int cur = MaxEven(a[i - 1]);
        if(cur == 0)L[i] = 0;
        else L[i] = L[i - 1] + cur;
    }
    R[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        int cur = MaxEven(a[i]);
        if(cur == 0)R[i] = 0;
        else R[i] = R[i + 1] + cur;
    }

    long long ans = 0, Max = 0;
    for(int i = 0; i < n; i++){
        Max += MaxOdd(a[i - 1]);
        Max = max(Max, L[i]);

        ans = max(ans, R[i] + Max);
    }
    cout << ans << endl;
    return 0;
}