#include<bits/stdc++.h>
using namespace std;
int ans,now1,now2,l[105],r[105],n,t1,t2,p1,p2,p3;
int main(){
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    for(int i=1;i<n;i++){
        ans+=p1*(r[i]-l[i]);
        now1=r[i]+t1;
        if(now1<l[i+1]){
            ans+=p1*t1;
            now2=now1+t2;
            if(now2<l[i+1]){
                ans+=t2*p2;
                ans+=p3*(l[i+1]-now2);
            }
            else ans+=p2*(l[i+1]-now1);
        }
        else ans+=(l[i+1]-r[i])*p1;
    }
    ans+=(r[n]-l[n])*p1;
    cout<<ans;
    return 0;
}