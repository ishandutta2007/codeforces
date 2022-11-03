//
//  main.cpp
//  C
//
//  Created by  on 16/5/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace  std;

const int maxn = 5000 + 5;

int n;

int t[maxn];
int num[maxn];
int ans[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) ans[i] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",t + i);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) num[j] = 0;
        int maxnum = 0,maxid = t[i];
        for(int j = i;j <= n;j++){
            num[t[j]]++;
            if(num[t[j]] > maxnum){
                maxnum = num[t[j]];
                maxid = t[j];
            }if(num[t[j]] == maxnum){
                if(t[j] < maxid){
                    maxid = t[j];
                }
            }
            ans[maxid]++;
        }
    }
    for(int i = 1;i <= n;i++) printf("%d ",ans[i]);
    return 0;
}