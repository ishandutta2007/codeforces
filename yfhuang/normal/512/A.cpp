//
//  main.cpp
//  A
//
//  Created by  on 10/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 30;

vector<int> G[maxn];

char s[105][105];

int deg[maxn];
char ans[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        scanf("%s",s[i] + 1);
    }
    memset(deg,0,sizeof(deg));
    for(int i = 1;i < n;i++){
        int len1 = strlen(s[i] + 1);
        int len2 = strlen(s[i + 1] + 1);
        int j;
        for(j = 1;j <= min(len1,len2);j++){
            if(s[i][j] != s[i + 1][j]){
                int x = s[i][j] - 'a';
                int y = s[i + 1][j] - 'a';
                G[y].push_back(x);
                G[x].push_back(y);
                deg[y]++;
                break;
            }
        }
        if(len1 > len2 && j == len2 + 1){
            flag = false;
        }
    }
    queue<int> q;
    for(int i = 0;i < 26;i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    int now = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans[now++] = x + 'a';
        for(int i = 0;i < G[x].size();i++){
            int v = G[x][i];
            deg[v]--;
            if(deg[v] == 0){
                q.push(v);
            }
        }
    }
    if(now != 26 || !flag){
        printf("Impossible\n");
    }
    else{ans[now] = 0;
        printf("%s",ans);}
    return 0;
}