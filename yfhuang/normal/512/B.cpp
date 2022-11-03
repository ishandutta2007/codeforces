//
//  main.cpp
//  B
//
//  Created by  on 10/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n;

const int maxn = 305;

int l[maxn],c[maxn];

map<int,long long> mp[2];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    int now = 0;
    mp[0].clear();
    mp[1].clear();
    for(int i = 1;i <= n;i++){
        map<int,long long> :: iterator it = mp[now ^ 1].begin();
        mp[now] = mp[now ^ 1];
        while(it != mp[now ^ 1].end()){
            int num = it->first;
            long long cost = it->second;
            int n1 = __gcd(num,l[i]);
            if(mp[now].count(n1)){
                mp[now][n1] = min(mp[now][n1],cost + c[i]);
            }else{
                mp[now][n1] = cost + c[i];
            }
            it++;
        }
        if(mp[now].count(l[i])){
            mp[now][l[i]] = min(mp[now][l[i]],(long long)c[i]);
        }else{
            mp[now][l[i]] = (long long)c[i];
        }
        mp[now ^ 1].clear();
        now = now ^ 1;
    }
    if(!mp[now ^ 1].count(1)){
        printf("-1\n");
    }else{
        cout << mp[now ^ 1][1] << endl;
    }
    return 0;
}