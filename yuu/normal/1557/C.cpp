#include <bits/stdc++.h>
using namespace std;
constexpr int base=1000000007;
int n, k;
long long f[200001];
long long r[200001];
long long power(long long x, long long y){
    if(y==0) return 1;
    long long t=power(x, y/2);
    (t*=t)%=base;
    if(y%2) (t*=x)%=base;
    return t;
}
long long C(int n, int k){
    return ((f[n]*r[k])%base*r[n-k])%base;
}
void solve(){
    cin>>n>>k;
    long long ans=0;
    long long multiplier=1;
    long long zzmul=0;
    for(int i=0; i<n; i+=2) (zzmul+=C(n, i))%=base;
    for(int i=0; i<k; i++){
        long long temp=0;
        if(n%2==0){
            //XOR == 0 && AND == 1
            (ans+=multiplier*power(power(2, k-i-1), n))%=base;
        }
        else{//XOR == AND == 1 
            temp+=1;
        }
        //XOR == 0 && AND == 0
        temp+=zzmul;
        (multiplier*=temp)%=base;
        //at least 1 0. even number of 1
    }
    (ans+=multiplier)%=base;
    cout<<ans<<'\n';
}
int main(){
    f[0]=1;
    for(int i=1; i<=200000; i++) f[i]=(f[i-1]*i)%base;
    r[200000]=power(f[200000], base-2);
    for(int i=200000; i>=1; i--) r[i-1]=(r[i]*i)%base;

    int t;
    cin>>t;
    while(t--) solve();
}