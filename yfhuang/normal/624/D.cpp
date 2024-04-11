//
//  main.cpp
//  D
//
//  Created by  on 16/2/5.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const ll INF=(1LL<<60)-1;
int c[maxn];
int f[2][maxn];
ll pre[maxn];
int p[105],cnt;

void get(int t){
    for(int i=2;i*i<=t;i++){
        if(t%i==0){
            p[cnt++]=i;
            while(t%i==0) t/=i;
        }
    }
    if(t!=1) p[cnt++]=t;
}

int main(int argc, const char * argv[]) {
    int n;
    ll a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    cnt=0;
    for(int i=-1;i<=1;i++){
        get(c[1]+i);
        get(c[n]+i);
    }
    sort(p,p+cnt);
    cnt=unique(p,p+cnt)-p;
    ll res=(n-1)*a;
    for(int i=0;i<cnt;i++){
        memset(f,0,sizeof(f));
        int g=p[i],t=n;
        for(int i=1;i<=n;i++){
            if(c[i]%g==0) f[0][i]=f[0][i-1];
            else if((c[i]-1)%g==0||(c[i]+1)%g==0) f[0][i]=f[0][i-1]+1;
            else{
                f[0][i]=-1;
                t=i-1;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(c[i]%g==0)f[1][i]=f[1][i+1];
            else if((c[i]-1)%g==0||(c[i]+1)%g==0) f[1][i]=f[1][i+1]+1;
            else{
                f[1][i]=-1;
                break;
            }
        }
        for(int i=1;i<=t;i++){
            pre[i]=min(pre[i-1],f[0][i]*b-i*a);//
        }
        for(int i=n+1;i>=1&&f[1][i]!=-1;i--){
            res=min(res,f[1][i]*b+i*a+pre[min(i-1,t)]-a);
        }
    }
    cout<<res<<endl;
    return 0;
}