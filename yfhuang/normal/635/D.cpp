//
//  main.cpp
//  d
//
//  Created by  on 16/2/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define lowbit(x) x&(-x)

typedef long long ll;

ll n,k,a,b,q;

const int maxn=2e5+10;

ll A[maxn];

ll prea[maxn],preb[maxn];

int Q[maxn];

ll sum(int x,ll *a){
    ll res=0;
    while(x>0){
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}

void update(int x,ll d,ll *a){
    while(x<maxn){
        a[x]+=d;
        x+=lowbit(x);
    }
}



int main(int argc, const char * argv[]) {
    cin>>n>>k>>a>>b>>q;
    memset(A,0,sizeof(A));
    memset(prea,0,sizeof(prea));
    memset(preb,0,sizeof(preb));
    for(int i=1;i<=q;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int d,ai;
            scanf("%d%d",&d,&ai);
            update(d,max(min(b-A[d],(ll)ai),0LL),preb);
            update(d,max(min(a-A[d],(ll)ai),0LL),prea);
            A[d]+=ai;
        }else{
            int p;
            scanf("%d",&p);
            cout<<sum(p-1,preb)+sum(maxn-1,prea)-sum(p+k-1,prea)<<endl;
        }
    }
    return 0;
}