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
int n, w, h, wi[5005], hi[5005], dp[5005], next[5005];
int f(int i){
    if(w >= wi[i] || h >= hi[i])return 0;
    if(dp[i] != -1)return dp[i];
    
    int ret = 1;
    for(int k = 0; k < n; k++)
        if(wi[k] < wi[i] && hi[k] < hi[i]){
            int x = f(k);
            if(x > 0){
                if(x + 1 > ret)
                    ret = x + 1, next[i] = k;
            }
        }
    return dp[i] = ret;
}
int main(){
    cin >> n >> w >> h;
    for(int i = 0; i < n; i++)
        cin >> wi[i] >> hi[i];

    int ans = -1, best = -1;

    memset(dp, -1, sizeof dp);
    memset(next, -1, sizeof next);
    for(int i = 0; i < n; i++){
        int ret = f(i);
        if(ans == -1 || ret > ans)
            ans = ret, best = i;
    }

    vector <int> v;
    while(ans--){
        v.push_back(best + 1);
        best = next[best];
    }
    cout << v.size() << endl;
    for(int i = v.size() - 1; i >= 0; i--){
        if(i + 1 < v.size())cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}