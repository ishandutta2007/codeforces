//
//  main.cpp
//  D
//
//  Created by  on 16/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll n,A,cf,cm,m;

const ll maxn=1e5+5;

ll a[maxn];

struct skill{
    ll v;
    int id;
    bool operator <(const skill& rhs) const{
        return v<rhs.v;
    }
}b[maxn];

ll pre[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>A>>cf>>cm>>m;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        b[i].v=a[i];
        b[i].id=i;
    }
    b[n+1].v=A;
    sort(b+1,b+n+1);
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]+(i-1)*(b[i].v-b[i-1].v);
    }
    pre[n+1]=pre[n]+n*(A-b[n].v);
    ll sum=0;
    ll ans=0,loc=n;
    for(int i=n;i>0;i--){
        ll rem=m-((n-i)*A-sum);
        int pos=upper_bound(pre+1, pre+i+1, rem)-pre;
        if(pos==1) break;
        ll now=(n-i)*cf+min(A,b[pos-1].v+(rem-pre[pos-1])/(pos-1))*cm;
        if(now>ans){
            ans=now;
            loc=i;
        }
        sum+=b[i].v;
    }
    //printf("%d ",loc);
    if(m-(n*A-sum)>=0){
        ans=n*cf+A*cm;
        loc=0;
    }
    for(int i=loc+1;i<=n;i++){
        m-=A-b[i].v;
        b[i].v=A;
    }
    int w=upper_bound(pre+1,pre+loc+1 ,m)-pre;
   // printf("%d ",w);
    for(int i=1;i<w;i++){
        b[i].v=min(A,b[w-1].v+(m-pre[w-1])/(w-1));
    }
    for(int i=1;i<=n;i++){
        a[b[i].id]=b[i].v;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        printf("%I64d ",a[i]);
    }
    return 0;
}