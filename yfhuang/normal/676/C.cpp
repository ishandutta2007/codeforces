//
//  main.cpp
//  C
//
//  Created by  on 16/5/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,k;
const int maxn = 1e5 + 5;

char c[maxn];

int a[maxn];
int b[maxn];

int ans[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    scanf("%s",c + 1);
    a[0] = b[0] = 0;
    memset(ans,0,sizeof(ans));
    for(int i = 1;i <= n;i++){
        if(c[i]== 'a'){
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
        }
        if(c[i]== 'b'){
            b[i] = b[i - 1] + 1;
            a[i] = a[i - 1];
        }
    }
    for(int i = 1;i <= n;i++){
        ans[i] = 0;
            if(b[i] <= k){
                ans[i] = max(ans[i],i);
            }else{
                int p = (int)(lower_bound(b, b + i, b[i] - k) - b);
                ans[i] = max(ans[i],i - p);
            }
            if(a[i] <= k){
                ans[i] = max(ans[i],i);
            }else{
                int p = (int)(lower_bound(a,a + i,a[i] - k) - a);
                ans[i] = max(ans[i],i - p);
            }
    }
    int res = 0;
    //for(int i = 1;i <= n;i++) cout << ans[i] << endl;
    for(int i = 1;i <= n;i++) res = max(res,ans[i]);
    cout << res << endl;
    return 0;
}