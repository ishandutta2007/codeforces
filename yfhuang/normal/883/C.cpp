#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
using namespace std;
const long long INF=1e18;
long long f,T,t0;
long long a1,t1,p1;
long long a2,t2,p2;

long long Solve(long long f,long long T,long long t0,long long a1,long long t1,long long p1,long long a2,long long t2,long long p2){
    long long lim1=f/a1+1;
    long long ans=INF;
    for (int i=0;i<=lim1;i++){
        long long ff=f-a1*i;
        if (ff<=0){
            if (T>=f*t1) ans=min(ans,p1*i);
        }
        else{
            long long TT=T-a1*i*t1;
            if (TT<0) continue;
            if (TT>=t0*ff) ans=min(ans,p1*i);
            else {
                if (t0<=t2) continue;
                long long tmp=(t0*ff-TT-1)/(t0-t2)+1;
                if (tmp>ff) continue;
                ans=min(ans,p1*i+p2*((tmp-1)/a2+1));
            }
        }
    }
    return ans;
}

int main(){
    scanf("%lld%lld%lld",&f,&T,&t0);
    scanf("%lld%lld%lld",&a1,&t1,&p1);
    scanf("%lld%lld%lld",&a2,&t2,&p2);
    long long ans=min(Solve(f,T,t0,a1,t1,p1,a2,t2,p2),Solve(f,T,t0,a2,t2,p2,a1,t1,p1));
    if (ans==INF) ans=-1;
    cout<<ans<<endl;
    return 0;
}