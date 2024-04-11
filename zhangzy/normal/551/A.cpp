#include<bits/stdc++.h>
using namespace std;

int n,a[2222],b[2222];

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for (int i=2;i<=2000;i++){
        b[i]+=b[i-1];
    }
    for (int i=1;i<=n;i++){
        printf("%d ",n-b[a[i]]+1);
    }
}