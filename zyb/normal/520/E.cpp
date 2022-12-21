#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mo 1000000007
#define N 100010
using namespace std;
typedef long long ll;
ll n,k;
ll fac[N],ifac[N];
char s[N];
inline ll Power(ll a,ll b){
    ll now=1;
    for(;b;b>>=1,a=1ll*a*a%mo)
     if(b&1) now=1ll*now*a%mo;
    return now;
}
ll a[N],f[N];
inline ll c(ll n,ll m){
    return 1ll*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
ll Sum[N];ll power[N];
inline ll Change(ll S,ll t){
    return (Sum[t]-Sum[S-1]*power[t-S+1]%mo+mo)%mo;
}
int main(){
    scanf("%I64d%I64d",&n,&k);
    scanf("%s",s+1);
    fac[0]=1;
    for(ll i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mo;
    ifac[0]=1;
    ifac[n]=Power(fac[n],mo-2);
    for(ll i=n-1;i;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mo;
    for(ll i=1;i<=n;i++)a[i]=s[i]-'0';
    for(ll i=1;i<=n;i++)Sum[i]=a[i];
    power[0]=1;
    for(int i=1;i<=n;i++)power[i]=(power[i-1]*10ll)%mo;
    for(ll i=2;i<=n;i++)Sum[i]=(Sum[i]+Sum[i-1]*10ll%mo)%mo;
    for(ll i=2;i<=n;i++)
    (a[i]+=a[i-1])%=mo;
    f[1]=a[n]%mo;for(ll i=2;i<=n;i++)f[i]=((1ll*f[i-1]*10ll%mo+(a[n]-a[i-1])%mo)%mo-1ll*Change(n-i+2,n)*10%mo+mo)%mo;
    if(k==0)printf("%I64d\n",f[n]);
    else 
    if(k==1){ll nowans=0;
   for(ll i=1;i<=n-1;i++)
   (nowans+=Change(1,i)+Change(n-i+1,n))%=mo;
        printf("%I64d\n",nowans);
    }else{
        ll nowans=0;for(ll i=1;i<=n-2-(k-2);i++){
            nowans=(1ll*nowans+1ll*f[i]*c(n-i-2,k-2)%mo)%mo;
        }for(ll i=1;i<=n-2-(k-2);i++){
            nowans=((1ll*nowans-1ll*Change(1,i)*c(n-i-2,k-2)%mo+mo)%mo-1ll*Change(n-i+1,n)*c(n-i-2,k-2)%mo+mo)%mo;
        }for(ll i=1;i<=n-k;i++){
            nowans=(1ll*nowans+1ll*(Change(1,i)+Change(n-i+1,n))*c(n-i-1,k-1)%mo)%mo;
        }
  printf("%I64d\n",nowans);
    }
}