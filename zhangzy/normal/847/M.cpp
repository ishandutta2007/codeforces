#include<bits/stdc++.h>
using namespace std;
int n,a[2333];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int fl=1;
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            if (a[i]-a[i+1]!=a[j]-a[j+1]){
                fl=0;
            }
        }
    }
    printf("%d\n",fl? a[n]*2-a[n-1] : a[n]);
}