//
//  main.cpp
//  B
//
//  Created by  on 9/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1005;

bool G[maxn][maxn];

int num[60];
int k;

void addedge(int i,int j){
    G[i][j] = true;
    G[j][i] = true;
}

int main(int argc, const char * argv[]) {
    cin >> k;
    int tot = 0;
    while(k > 0){
        if(k & 1){
            num[++tot] = 1;
        }else{
            num[++tot] = 0;
        }
        k >>= 1;
    }
    memset(G,false,sizeof(G));
    for(int i = 3,j = 1;j <= tot;j++,i += 2){
        if(i == 3) continue;
        else{
            addedge(i,i - 1);addedge(i,i - 2);
            addedge(i + 1,i - 1);addedge(i + 1,i - 2);
        }
    }
    //cout << tot << endl;
    addedge(tot * 2 + 1,2);
    addedge(tot * 2 + 2,2);
    int rear = tot * 2 + 2 + 1;
    for(int i = tot;i >= 1;i--){
        if(num[i] == 1){
            int dep = tot - i;
            if(dep > 0){
                addedge(1,rear);
                for(int i = 1;i < dep;i++){
                    addedge(rear,rear + 1);
                    rear++;
                }
                addedge(rear,2 * dep + 3);
                rear++;
            }else{
                addedge(1,2 * dep + 3);
                rear++;
            }
        }
    }
    printf("1000\n");
    for(int i = 1;i <= 1000;i++){
        for(int j = 1;j <= 1000;j++){
            if(G[i][j]) printf("Y");
            else printf("N");
        }
        puts("");
    }
    return 0;
}