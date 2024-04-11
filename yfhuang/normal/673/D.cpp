//
//  main.cpp
//  D
//
//  Created by  on 16/5/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,k;

int a,b,c,d;

const int maxn = 1005;

int t[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(n == 4){
        cout << -1 << endl;
    }else{
        if(k <= n){
            cout << -1 << endl;
        }else{
            t[1] = a;
            t[2] = c;
            int id = 2;
            for(int i = 1;i <= n;i++){
                if(i == a || i == b || i == c || i == d) continue;
                else t[++id] = i;
            }
            t[n - 1] = d;
            t[n] = b;
            for(int i = 1;i <= n;i++){
                printf("%d%c",t[i],i == n ?'\n':' ' );
            }
            printf("%d %d %d ",t[2],t[1],t[3]);
            for(int i = 4;i < n - 1;i++){
                printf("%d ",t[i]);
            }
            printf("%d %d\n",t[n],t[n - 1]);
        }
    }
    return 0;
}