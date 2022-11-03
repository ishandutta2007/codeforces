//
//  main.cpp
//  C
//
//  Created by  on 16/4/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k;

const int maxn = 3e5 + 5;

int a[maxn];
int n0[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    n0[0] = 0;
    for(int i = 1;i <= n;i++){
        n0[i] = n0[i - 1] + (a[i] == 0);
    }
    //cout << n0[n] << endl;
    if(n0[n] <= k){
        cout << n <<endl;
        for(int i = 1;i <= n;i++){
            printf("1%c",i == n ?'\n':' ');
        }
        return 0;
    }else{
        int ans = -1,id = -1;
        for(int i = 1;i <= n;i++){
            while(i < n && n0[i + 1] == n0[i]){
                i++;
            }
            int minVal = n0[i] - k;
            if(minVal <= 0){
                if(i > ans){
                    ans = i;
                    id = i;
                }
            }else{
                int j = lower_bound(n0 + 1,n0 + n,minVal) - n0;
                if(i - j > ans){
                    ans = i - j;
                    id = i;
                }
            }
        }
        cout << ans << endl;
        int cnt = 0;
        for(int i = id;i >0 ;i--){
            if(cnt == k) break;
            if(a[i] == 1) continue;
            else{
                a[i] = 1;
                cnt++;
            }
        }
        for(int i = 1;i <= n;i++){
            printf("%d%c",a[i],i == n ? '\n':' ');
        }
    }
    return 0;
}