//
//  main.cpp
//  C
//
//  Created by  on 9/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;

int a[maxn];

int s1[maxn];
int s2[maxn];
int mid[maxn];
int tot;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    tot = 0;
    for(int i = 1;i <= n;i++){
        int s;
        scanf("%d",&s);
        for(int j = 1;j <= s;j++){
            scanf("%d",a + j);
        }
        for(int j = 1;j <= s / 2;j++){
            s1[i] += a[j];
        }
        for(int j = (s + 1) / 2 + 1;j <= s;j++){
            s2[i] += a[j];
        }
        if(s & 1) mid[++tot] = a[(s + 1) / 2];
    }
    sort(mid + 1,mid + 1 + tot);
    int sum1 = 0,sum2 = 0;
    for(int i = tot;i >= 1;i--){
        if((tot - i) % 2 == 0)sum1 += mid[i];
        else sum2 += mid[i];
    }
    for(int i = 1;i <= n;i++){
        sum1 += s1[i];
        sum2 += s2[i];
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}