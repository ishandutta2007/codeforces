//
//  main.cpp
//  B
//
//  Created by  on 16/7/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;

int cnt[1005];
int cnt1[1005];

char grid[1005][1005];

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%s",grid[i] + 1);
    }
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(grid[i][j] == '*') cnt[i]++;
        }
    }
    //for(int i = 1;i <= n;i++) cout << cnt[i] << endl;
    bool flag = false;
    int ansx = 1,ansy = 1;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(grid[j][i] == '*') cnt1[j] = cnt[j] - 1;
            else cnt1[j] = cnt[j];
        }
        //for(int i = 1;i <= n;i++) cout << cnt1[i] << endl;
        int num = 0;
        for(int j = 1;j <= n;j++){
            if(cnt1[j] > 0) num++;
        }
        if(num <= 1){
            flag = true;
            for(int j = 1;j <= n;j++){
                if(cnt1[j] > 0) ansx = j;
            }
            ansy = i;
        }
        if(flag) break;
    }
    if(flag){puts("YES");
        printf("%d %d\n",ansx,ansy);}
    if(!flag) printf("NO\n");
    return 0;
}