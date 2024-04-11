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
int n, q[100005], minX[100005];
int BinarySearch(int i){
    int lo = i + 1, hi = n - 1;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(minX[mid] < q[i])lo = mid;
        else hi = mid - 1;
    }
    if(minX[hi] < q[i])return hi;
    else if(minX[lo] < q[i])return lo;
    else return -1;
}
int main(){
//    freopen("a.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> q[i];
    minX[n - 1] = q[n - 1];
    for(int i = n - 2; i >= 0; i--)
        minX[i] = min(minX[i + 1], q[i]);
    for(int i = 0; i < n - 1; i++){
        int ans = BinarySearch(i);
        if(ans == -1)cout << -1 << ' ';
        else cout << ans - i - 1 << ' ';
    }
    cout << -1 << endl;
    return 0;
}