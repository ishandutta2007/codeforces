//
//  main.cpp
//  E
//
//  Created by  on 16/2/5.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

const int maxn=1e5+5;
const int INF=2e8;

struct point{
    int x,y;
    bool operator <(const point &rhs) const{
        return x<rhs.x;
    }
}v[maxn];

int vmax[maxn],vmin[maxn];

long long solve(){
    long long l=0,r=1LL*INF*INF;
    while(l<=r){
        long long mid=(l+r)/2;
        int maxx=-INF,minx=INF;bool ok=false;
        for(int i=1,j=1;j<=n;j++){
            while(1LL*(v[j].x-v[i].x)*(v[j].x-v[i].x)>mid){
                maxx=max(maxx,v[i].y);
                minx=min(minx,v[i].y);
                i++;
            }
            int a=max(maxx,vmax[j+1]),b=min(minx,vmin[j+1]);
            if(a<b) {ok=1;break;}
            if(1LL*(a-b)*(a-b)>mid) continue;
            if(1LL*a*a+1LL*v[i].x*v[i].x>mid) continue;
            if(1LL*a*a+1LL*v[j].x*v[j].x>mid) continue;
            if(1LL*b*b+1LL*v[i].x*v[i].x>mid) continue;
            if(1LL*b*b+1LL*v[j].x*v[j].x>mid) continue;
            ok=1;break;
        }
        if(ok) r=mid-1;
        else l=mid+1;
    }
    return l;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i].x,&v[i].y);
    }
    sort(v+1,v+1+n);
    vmax[n+1]=-INF;
    vmin[n+1]=INF;
    for(int i=n;i>0;i--){
        vmax[i]=max(vmax[i+1],v[i].y);
        vmin[i]=min(vmin[i+1],v[i].y);
    }
    long long ans=min(1LL*(v[n].x-v[1].x)*(v[n].x-v[1].x),1LL*(vmax[1]-vmin[1])*(vmax[1]-vmin[1]));
    ans=min(ans,solve());
    for(int i=1;i<=n;i++) swap(v[i].x,v[i].y);
    sort(v+1,v+1+n);
    vmax[n+1]=-INF;vmin[n+1]=INF;
    for(int i=n;i;i--)
    {
        vmax[i]=max(vmax[i+1],v[i].y);
        vmin[i]=min(vmin[i+1],v[i].y);
    }
    ans=min(ans,solve());
    cout<<ans<<endl;;
    return 0;
}