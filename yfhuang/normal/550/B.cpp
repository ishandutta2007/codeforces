//
//  main.cpp
//  B
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

const int N=16;

int a[N];

int l,r,x;

int main(int argc, const char * argv[]) {
    cin>>n>>l>>r>>x;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    for(int j=0;j<(1<<n);j++){
        int cnt=0;
        int b[N];
        for(int k=1;k<=n;k++){
            if(j&(1<<(k-1))) {cnt++;b[cnt]=a[k];}
        }
        if(cnt<2) continue;
        int sum=0;
        for(int k=1;k<=cnt;k++){
                sum+=b[k];
        }
        if(b[cnt]-b[1]>=x&&sum>=l&&sum<=r) ans++;
    }
    printf("%d\n",ans);
    return 0;
}