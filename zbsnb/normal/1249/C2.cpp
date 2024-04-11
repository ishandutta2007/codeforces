#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll f[100];
int main(){
    int t;cin>>t;
    f[0]=1;
    int now=0;
    while(f[now]<=1e18){
        now++;
        f[now]=f[now-1]*3;
    }
    //cout<<now<<endl;
    while(t--){
        ll n;cin>>n;
        ll l=0,r=(1ll<<(now+1))-1;
        //cout<<r<<endl;
        ll ans=0;
        while(l<=r){
            //cout<<l<<r<<endl;
            ll m=l+r>>1;
            ll tmp=0;
            for(int i=0;i<60;i++){
                if(m&(1ll<<i))tmp+=f[i];
            }
            if(tmp>=n){
                ans=tmp;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        cout<<ans<<endl;
    }
}