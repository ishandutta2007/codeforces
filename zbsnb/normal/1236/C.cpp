#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define ll long long 
const ll mod=998244353;

int main(){
    int n;cin>>n;
    if(n%2==1){
        for(int i=0;i<=n-1;i++)cout<<n/2+1+i*n<<" ";cout<<endl;
        for(int i=1;i<=n/2;i++){
            for(int j=0;j<=n-1;j++)cout<<(j%2==0?(n+1-i):i)+j*n<<" ";cout<<endl;
            for(int j=0;j<=n-1;j++)cout<<(j%2==1?(n+1-i):i)+j*n<<" ";cout<<endl;
        }
    }
    else{
        for(int i=1;i<=n/2;i++){
            for(int j=0;j<=n-1;j++)cout<<(j%2==0?(n+1-i):i)+j*n<<" ";cout<<endl;
            for(int j=0;j<=n-1;j++)cout<<(j%2==1?(n+1-i):i)+j*n<<" ";cout<<endl;
        }
    }
}