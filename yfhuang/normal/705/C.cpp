//
//  main.cpp
//  C
//
//  Created by  on 8/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 300000 + 5;

queue<int> q[maxn];

int n,Q;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> Q;
    int type,x,t;
    int sum = 0;
    int T = 0;
    int pre = 0;
    while(Q--){
        scanf("%d",&type);
        if(type == 1){
            scanf("%d",&x);
            q[x].push(++T);
            a[T] = x;
            sum++;
            printf("%d\n",sum);
        }else if(type == 2){
            scanf("%d",&x);
            while(!q[x].empty()){
                sum--;
                q[x].pop();
            }
            printf("%d\n",sum);
        }else if(type == 3){
            scanf("%d",&t);
            for(int i = pre + 1;i <= t;i++){
                while(!q[a[i]].empty() && q[a[i]].front() <= t){
                    sum--;
                    q[a[i]].pop();
                }
            }
            pre = max(pre,t);
            printf("%d\n",sum);
        }
    }
    return 0;
}