//
//  main.cpp
//  B
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;

bool vis[maxn];
int d[maxn];
int dir[maxn];
char s[maxn];
int n;
int main(int argc, const char * argv[]) {
    cin >> n;
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i++){
        if(s[i] == '>')dir[i] = 1;
        else dir[i] = -1;
        vis[i] = false;
    }
    for(int i = 1;i <= n;i++)
        scanf("%d",&d[i]);
    long long pos = 1;
    vis[pos] = true;
    bool flag = true;
    for(;;){
        pos = pos + (long long)dir[pos] * (long long)d[pos];
        if(pos < 1 || pos > n){
            break;
        }else{
            if(vis[pos]){
                flag = false;
                break;
            }else{
                vis[pos] = true;
            }
        }
    }
    if(!flag) cout << "INFINITE" << endl;
    else cout << "FINITE" << endl;
    return 0;
}