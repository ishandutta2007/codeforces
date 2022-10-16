#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int n;
int main(){
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i][i];
        a[i][i]=0;
    }
    for(int i=0; i<n; i++){
        sum+=a[i][n-1-i];
        a[i][n-1-i]=0;
    }
    for(int i=0; i<n; i++){
        sum+=a[i][n/2];
        a[i][n/2]=0;
    }
    for(int i=0; i<n; i++){
        sum+=a[n/2][i];
        a[n/2][i]=0;
    }
    cout<<sum<<'\n';
}