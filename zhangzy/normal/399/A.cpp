#include<bits/stdc++.h>
using namespace std;
int n,p,k;
int main(){
    cin>>n>>p>>k;
    if (p-k>1){
        printf("<< ");
    }
    for (int i=max(1,p-k);i<p;i++){
        printf("%d ",i);
    }
    printf("(%d)",p);
    for (int i=p+1;i<=min(n,p+k);i++){
        printf(" %d",i);
    }
    if (p+k<n){
        printf(" >>");
    }
}