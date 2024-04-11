#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=998244353;
const int N=2e5+5;

ll n,pw[N];

int main(){
    cin>>n, pw[0]=1;
    for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%mod;
    for(int i=1;i<=n;i++){
        if(i==n)puts("10");
        else{
            ll mid=n-i-1,lr=2;
            mid=pw[n-i-1]*mid*9*9%mod,lr=lr*9*pw[n-i]%mod;
            cout<<(mid+lr)%mod<<" ";
        }
    }
    return 0;
}