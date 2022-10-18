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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int c[m];
    for(int i =0;i<m;i++)c[i] = INT_MAX;
    while(n--){
        int r,i;
        cin >> r >> i;
        c[r-1] = min(c[r-1],i);
    }
    int sum = 0;
    for(int i =0;i<m;i++){
        if(c[i] != INT_MAX)sum += c[i];
    }
    cout << min(k,sum) << endl;
    return 0;
}