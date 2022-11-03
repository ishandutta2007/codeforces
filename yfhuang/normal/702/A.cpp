//
//  main.cpp
//  A
//
//  Created by  on 7/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

const int maxn = 1e5 + 5;
const int INF = 1e9 + 5;

int a[maxn];
//int g[maxn],d[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++) scanf("%d",a + i);
    int tmp = 1;
    int ans = 1;
    for(int i = 2;i <= n;i++){
        if(a[i] <= a[i - 1]){
            ans = max(ans,tmp);
            tmp = 1;
        }else{
            tmp++;
        }
    }
    ans = max(ans,tmp);
    cout << ans << endl;
//    for(int i = 1;i <= n;i++) g[i] = INF;
//    for(int i = 1;i <= n;i++){
//        int k = lower_bound(g + 1,g + 1 + n , a[i]) - g;
//        d[i] = k;
//        g[k] = a[i];
//    }
//    int ans = 0;
//    for(int i = 1;i <= n;i++) ans = max(ans,d[i]);
//    cout << ans << endl;
    return 0;
}