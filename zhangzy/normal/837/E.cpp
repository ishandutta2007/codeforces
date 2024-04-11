#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool pri(ll x){
    if (x==2) return 1;
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            return 0;
        }
    }
    return 1;
}

ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}

ll F(ll x,ll y){
    if (pri(x)){
        return x>y?y:y/x+y%x;
    }
    ll cnt=0,g;
    while (1){
        if (y==0) return cnt;
        g=gcd(x,y);
        if (g==1){
            y--;
            cnt++;
        }else{
            return cnt+F(x/g,y/g);
        }
    }
}

int main(){
    ll x,y;
    cin>>x>>y;
    cout<<F(x,y);
}