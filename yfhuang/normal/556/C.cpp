//
//  main.cpp
//  C
//
//  Created by  on 16/1/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=1e5+5;
const int K=1e5+5;

int n,k;

int a[N];

int main()
{
    int n,m,k,ans,a;
    cin>>n>>m;
    ans = 2 * n - m + 1;
    for (int i = 0; i < m; i++)
    {
        cin>>k;
        for (int i = 0; i < k; i++)
        {
            cin>>a;
            if (a == i + 1)
                ans -= 2;
        }
    }
    cout<<ans;
    return 0;
}