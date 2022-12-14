#include<bits/stdc++.h>
using namespace std;
long long int a[2001][4][1000];
long long int mod=998244353;
int main(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<2<<endl;
        return 0;
    }
    for(int j=0;j<n;j++){
        a[1][0][j]=a[1][2][j]=0;
        a[1][1][j]=a[1][3][j]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                if(i==1){
                    a[i][0][0]=a[i][2][0]=0;
                    a[i][1][0]=a[i][3][0]=1;
                }
                else if(i==2){
                    a[i][0][0]=a[i][2][0]=1;
                    a[i][1][0]=a[i][3][0]=0;
                }
                else{
                    a[i][0][0]=a[i][1][0]=a[i][2][0]=a[i][3][0]=0;
                }
            }
            else{
                a[i][0][j]=(a[i][0][j-1]+a[i-1][1][j-1]+a[i-2][2][j-1]+a[i-1][3][j-1])%mod;
                a[i][1][j]=(a[i][0][j-1]+a[i][1][j-1]+a[i][2][j-1]+a[i-1][3][j-1])%mod;
                a[i][2][j]=(a[i-2][0][j-1]+a[i-1][1][j-1]+a[i][2][j-1]+a[i-1][3][j-1])%mod;
                a[i][3][j]=(a[i][0][j-1]+a[i-1][1][j-1]+a[i][2][j-1]+a[i][3][j-1])%mod;
            }
        }
    }
    cout<<(a[k][0][n-1]+a[k][1][n-1]+a[k][2][n-1]+a[k][3][n-1])%mod<<endl;
}