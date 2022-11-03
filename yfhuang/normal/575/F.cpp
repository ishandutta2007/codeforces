//
//  main.cpp
//  F
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5005;
typedef long long ll;
const ll INF=1e18;

int l[maxn],r[maxn];
ll pos[maxn*2];
 ll dp[2][maxn*2];


int main(int argc, const char * argv[]) {
    int n,x;
    cin>>n>>x;
    int k=0;
    pos[k++]=x;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        pos[k++]=l[i];
        pos[k++]=r[i];
    }
    sort(pos,pos+k);
    k=unique(pos, pos+k)-pos;
    for(int i=0;i<k;i++){
        dp[0][i]=abs(pos[i]-x);
    }
    for(int i=1;i<=n;i++){
        ll tmp1=INF;
        for(int j=0;j<k;j++){
            dp[i%2][j]=INF;
            ll tmp2=0;
            if(pos[j]<l[i]) tmp2=l[i]-pos[j];
            else if(pos[j]>r[i]) tmp2=pos[j]-r[i];
            if(j==0) tmp1=dp[(i-1)%2][j];
            else tmp1=min(dp[(i-1)%2][j],tmp1+pos[j]-pos[j-1]);
            dp[i%2][j]=min(dp[i%2][j],tmp1+tmp2);
        }
        tmp1=INF;
        for(int j=k-1;j>=0;j--){
            //dp[i%2][j]=INF;
            ll tmp2=0;
            if(pos[j]<l[i]) tmp2=l[i]-pos[j];
            else if(pos[j]>r[i]) tmp2=pos[j]-r[i];
            if(j==k-1) tmp1=dp[(i-1)%2][j];
            else tmp1=min(dp[(i-1)%2][j],tmp1+pos[j+1]-pos[j]);
            dp[i%2][j]=min(dp[i%2][j],tmp1+tmp2);
        }
    }
    ll ans=INF;
    for(int i=0;i<k;i++){
        ans=min(ans,dp[n%2][i]);
    }
    cout<<ans<<endl;
    return 0;
}