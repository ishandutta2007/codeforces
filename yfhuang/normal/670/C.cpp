//
//  main.cpp
//  C
//
//  Created by  on 16/5/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 200000 + 5;

map<int,int> mp;

int n,m;

int b[maxn],c[maxn];

int main(int argc, const char * argv[]) {
    mp.clear();
    cin >> n;
    int a;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a);
        mp[a]++;
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d",&b[i]);
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&c[i]);
    }
    int id = 1;
    int ss = mp[b[1]];
    int s = mp[c[1]];
    for(int i = 2;i <= m;i++){
        if(mp[b[i]] > ss){
            id = i;
            ss = mp[b[i]];
            s = mp[c[i]];
        }else if(mp[b[i]] == ss){
            if( mp[c[i]] > s){
                id = i;
                s = mp[c[i]];
            }
        }
    }
    cout << id << endl;
    return 0;
}