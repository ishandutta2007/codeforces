#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[100100];

bool C(ll x){
    ll t,p1=1,p2=0;
    for (int i=1;i<=m;i++){
        t=x-p1;
        while (p1<=n&&t>=a[p1]-p2){
            t-=a[p1]-p2;
            p1++;p2=0;t--;
        }
        if (t>0){
            p2+=t;
        }
        if (p1>n) return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while (a[n]==0&&n>0) n--;
    if (n==0){
        printf("0\n");
        return 0;
    }
    ll l=n,r=200000000000000,mid,ans;
    while (l<=r){
        mid=(l+r)>>1;
        if (C(mid)){
            r=(ans=mid)-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}