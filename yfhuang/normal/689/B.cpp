//
//  main.cpp
//  B
//
//  Created by  on 16/7/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

const int INF = 0x3f3f3f3f;

int d[maxn];

bool inq[maxn];


void bfs(int i){
    d[1] = 0;
    queue<int> q;
    q.push(1);
    inq[1] = true;
    while(!q.empty()){
        int p = q.front();q.pop();
        inq[p] = false;
        
            if(p > 1)if(d[p - 1] > d[p] + 1){
                d[p - 1] = d[p] + 1;
                q.push(p - 1);
                inq[p - 1] = true;
            }
        if(p < n)if(d[p + 1] > d[p] + 1){
                d[p + 1] = d[p] + 1;
                q.push(p + 1);
                inq[p + 1] = true;
            }
        //cout << "yes" << endl;
        if(d[a[p]] > d[p] + 1){
            //cout << "yes" << endl;
            d[a[p]] = d[p] + 1;
            q.push(a[p]);
            inq[a[p]] = true;
        }
    }
}



int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    memset(d,INF,sizeof(d));
    memset(inq,false,sizeof(inq));
    bfs(1);
    for(int i = 1;i <= n;i++){
        printf("%d%c",d[i],i == n ? '\n':' ');
    }
    return 0;
}