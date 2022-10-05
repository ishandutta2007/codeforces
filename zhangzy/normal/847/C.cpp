#include<bits/stdc++.h>
#define ll long long
using namespace std;

void doit(ll n,ll k){
    if (k==0){
        for (int i=1;i<=n;i++){
            printf("()");
        }
        return;
    }
    if (k>=n-1){
        printf("(");
        doit(n-1,k-n+1);
        printf(")");
    }else{
        printf("(");
        doit(k,0);
        printf(")");
        doit(n-1-k,0);
    }
}

int main(){
    ll n,k;
    cin>>n>>k;
    if (n*(n-1)/2<k){
        puts("Impossible");
        return 0;
    }
    doit(n,k);
}