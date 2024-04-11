//
//  main.cpp
//  A
//
//  Created by  on 9/6/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;

int num[maxn];
int a[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    memset(num,0,sizeof(num));
    int tot = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(num[j] <= a[i]){
                if(num[j] == 0) tot++;
                num[j]++;
                break;
            }
        }
    }
    cout << tot << endl;
    return 0;
}