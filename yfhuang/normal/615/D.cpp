//
//  main.cpp
//  D
//
//  Created by  on 16/1/8.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD=1e9+7;

typedef  long long ll;

ll mod_pow(ll x,ll n){
    ll ans=1;
    while(n>0){
        if(n&1)
        ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}

bool is_prime[200005];

struct prime{
    ll v,id;
};
ll c[200005];
ll pre[200005],suf[200005];
vector<prime>p;

void table(){
    for(int i=2;i<=200000;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=200000;j+=i)
                is_prime[j]=false;
        }
    }
    for(int i=2;i<=200000;i++){
        if(is_prime[i]&&c[i]!=0){
            prime a;
            a.v=(long long)c[i];
            a.id=(long long) i;
            p.push_back(a);
        }
    }
}

int main(int argc, const char * argv[]) {
    int m;
    cin>>m;
    memset(c,0,sizeof(c));
    memset(is_prime,true,sizeof(is_prime));
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        c[x]++;
    }
    table();
    ll sum=1;
    //for(int i=0;i<p.size();i++){
    //    sum*=p[i].v+1;
    //    while(sum>=MOD-1) sum-=MOD-1;
    //}
    //for(int i=0;i<p.size();i++){
    //    printf("%d %d ",p[i].v,p[i].id);
    //}
    pre[0]=1;
    for(int i=1;i<p.size();i++){
        pre[i]=pre[i-1]*(p[i-1].v+1)%(MOD-1);
    }
    suf[p.size()-1]=1;
    for(int i=p.size()-2;i>=0;i--){
        suf[i]=suf[i+1]*(p[i+1].v+1)%(MOD-1);
    }
        
    ll ans=1;
    for(int i=0;i<p.size();i++){
        sum=1;
        sum=pre[i]*suf[i]%(MOD-1);
        //printf("%d %d ",p[i].v,p[i].id);
       // printf("%d ",sum);
        ll d=p[i].v*(p[i].v+1)/2;
        ll b=mod_pow(p[i].id,d);
        if(p.size()==1) ans=b%MOD;
        //printf(" %d ",b);
        else ans=ans*mod_pow(b,sum)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}