#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define INF 1000000

int n;
main(){
    int i,j;
    while(cin >> n){
        int lis[100005];
        int v[100005];
        REP(i, n) cin >> v[i];
        REP(i, n) lis[i] = INF;
        REP(i, n) *upper_bound(lis, lis+n, v[i]) = v[i];
        cout << find(lis, lis+n, INF) - lis << endl;
    }
    return 0;
}