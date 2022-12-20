#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
ll x,y,pr[10000005],cnt,vis[100005];
ll gcd(ll x,ll y){
    return x==0?y:gcd(y%x,x);
}

void pre(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;pr[++cnt]=i;
            for(int j=i;j<=lim/i;j++){
                vis[i*j]=1;
            }
        }   
    }
}

inline bool isprime(int x){
    int lim=sqrt(x)+1;
    for(int i=2;i<=lim;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    scanf("%d",&n);pre(100000);
    while(n--){
        scanf("%lld%lld",&x,&y);
        if(x%y!=0) cout<<x<<endl;
        else{
            ll tmp=sqrt(y)+1,t=x/y,ans=1;
            for(int i=1;i<=tmp;i++){
                if(y%i) continue;
                ll q1=i,q2=y/i;
                if((q1%y)&&q1>ans) ans=q1;
                if((q2%y)&&q2>ans) ans=q2;
            }
            for(int i=1;i<=cnt;i++){
                ll cs=0;tmp=y;ll res=1;
                while(tmp%pr[i]==0) tmp/=pr[i],cs++,res*=pr[i];
                res/=pr[i];
                if(res&&x%res==0){
                    ll kkk=x;while(kkk%pr[i]==0) kkk/=pr[i];
                    ans=max(ans,res*kkk);
                }   
            }
            if(tmp>1){
                ll cs=0;tmp=y;ll p=tmp;ll res=1;
                while(tmp%p==0) tmp/=p,cs++,res*=p;
                res/=p;
                if(res&&x%res==0){
                    ll kkk=x;while(kkk%p==0) kkk/=p;
                    ans=max(ans,res*kkk);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}