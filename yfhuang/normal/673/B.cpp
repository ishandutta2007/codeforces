//
//  main.cpp
//  B
//
//  Created by  on 16/5/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;

int n,m;

int u[maxn],v[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        u[i] = min(x,y);
        v[i] = max(x,y);
    }
    if(m == 0){
        cout << n - 1 << endl;
    }else{
        int maxu = 0,minv = n + 1;
        for(int i = 1;i <= m;i++){
            maxu = max(maxu,u[i]);
            minv = min(minv,v[i]);
        }
        if(maxu >= minv){
            cout << 0 << endl;
        }else{
            cout << minv - maxu << endl;
        }
    }
    return 0;
}