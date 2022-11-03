//
//  main.cpp
//  A
//
//  Created by  on 9/17/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,c;

const int maxn = 1e5 + 5;
int t[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> c;
    for(int i = 1;i <= n;i++) scanf("%d",t + i);
    int now = 0;
    for(int i = 1;i <= n;i++){
        now++;
        if(i < n && t[i + 1] - t[i] > c){
            now = 0;
        }
    }
    cout << now << endl;
    return 0;
}