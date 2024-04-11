#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
const int maxn=105;

struct apple{
    int x,a;
}p[maxn],m[maxn];

bool cmp1(apple a,apple b){
    return a.x<b.x;
}

bool cmp2(apple a,apple b){
    return a.x>b.x;
}

int main(){
    scanf("%d",&n);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        int x,a;
        scanf("%d%d",&x,&a);
        if(x>0){
            p[cnt1].x=x;
            p[cnt1++].a=a;
        }else{
            m[cnt2].x=x;
            m[cnt2++].a=a;
        }
    }
    sort(p,p+cnt1,cmp1);
    sort(m,m+cnt2,cmp2);
    long long ans=0;
    if(cnt1==cnt2){
        for(int i=0;i<cnt1;i++){
            ans+=p[i].a+m[i].a;
        }
    }else if(cnt1>cnt2){
        for(int i=0;i<cnt2+1;i++){
            ans+=p[i].a;
        }
        for(int i=0;i<cnt2;i++){
            ans+=m[i].a;
        }
    }else if(cnt1<cnt2){
        for(int i=0;i<cnt1+1;i++){
            ans+=m[i].a;
        }
        for(int i=0;i<cnt1;i++){
            ans+=p[i].a;
        }
    }
    cout<<ans<<endl;
    return 0;
}