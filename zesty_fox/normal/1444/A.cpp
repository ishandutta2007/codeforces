#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=100010;
ll T,p,q,pr[N],cnt,vis[N];
void pre(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;pr[++cnt]=i;
            for(int j=i;j<=lim/i;j++) vis[i*j]=1;
        }   
    }
}
 
int main(){
    scanf("%d",&T);pre(N-1);
    while(T--){
        scanf("%lld%lld",&p,&q);
        if(p%q!=0) cout<<p<<endl;
        else{
            ll ans=1,tmp=q;
            for(int i=1;i<=cnt;i++){
                ll cs=0,res=1;
                while(tmp%pr[i]==0) tmp/=pr[i],cs++,res*=pr[i];
                if(!cs) continue;//csa_i
                res/=pr[i];//res=pr[i]^(a_i-1)
                if(p%res==0){
                    ll tmp1=p;while(tmp1%pr[i]==0) tmp1/=pr[i];
                    ans=max(ans,res*tmp1);
                }   
            }
            if(tmp>1){//tmptmp
                ll res=1;
                //res1
                if(p%res==0){
                    ll tmp1=p;while(tmp1%tmp==0) tmp1/=tmp;
                    ans=max(ans,res*tmp1);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}