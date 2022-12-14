#include<bits/stdc++.h>

using namespace std;
int a[1000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,ans;
    cin>>n;
    int sqrtn=(int) sqrt(n);
    if(sqrtn*sqrtn==n)  ans=sqrtn;
    else    ans=sqrtn+1;
    int k=((n-1)/ans)*ans+1;
    while(k!=n+1){
        cout<<k<<' ';
        k++;
    }
    a[1]=((n-1)/ans-1)*ans+1;
    for(int i=2;i<=ans;i++){
        a[i]=a[i-1]+1;
    }
    for(int i=1;i<=(n-1)/ans;i++){
        for(int j=1;j<=ans;j++){
            cout<<a[j]<<' ';
            a[j]-=ans;
        }
    }
}