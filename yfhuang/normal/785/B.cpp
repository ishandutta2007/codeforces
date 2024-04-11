//
//  main.cpp
//  B
//
//  Created by  on 2017/3/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;

const int maxn = 2e5 + 5;

int L[maxn],R[maxn];
int L1[maxn],R1[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> L[i] >> R[i];
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> L1[i] >> R1[i];
    }
    int mi = 1e9 + 7;
    int mx = -1;
    for(int i = 1;i <= n;i++){
        mi = min(R[i],mi);
        mx = max(L[i],mx);
    }
    int ans = 0;
    for(int i = 1;i <= m;i++){
        ans = max(ans,max(max(mx - R1[i],0),max(L1[i] - mi,0)));
    }
    cout << ans << endl;
    return 0;
}