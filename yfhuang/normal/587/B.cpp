//
//  main.cpp
//  D
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int mod=1e9+7;
const int N=1e6+5;
vector<int> dp[N];

int a[N];

void add(int& a,int b){
    a+=b;
    while(a>=mod)
        a-=mod;
}

int main(int argc, const char * argv[]) {
    int n,k;
    long long l;
    cin>>n>>l>>k;
    for(int i=0;i<n;i++)
        dp[i].resize(k+1);
    vector<int> vals;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        vals.push_back(a[i]);
    }
    sort(vals.begin(),vals.end());
    vals.resize(unique(vals.begin(), vals.end())-vals.begin());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(vals.begin(), vals.end(), a[i])-vals.begin();
        dp[i][1]=1;
    }
    vector<int> cnt;
    cnt.resize(vals.size());
    for (int j = 2; j <= k; j++)
    {
        for (int i = 0; i < (int)cnt.size(); i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
            add(cnt[a[i]], dp[i][j - 1]);
        for (int i = 1; i < (int)cnt.size(); i++)
            add(cnt[i], cnt[i - 1]);
        for (int i = 0; i < n; i++)
            dp[i][j] = cnt[a[i]];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            long long b=l/n;
            if(i<l%n)
                b++;
            b=b-j+1;
            if(b>0){
                ans=(ans+(b%mod)*dp[i][j])%mod;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}