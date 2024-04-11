#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    if(k<3||k>=2*n)
        cout<<0<<endl;
    else if(k<=n+1)
        cout<<k/2-1+k%2<<endl;
    else
        cout<<(2*n-k+2)/2-1+k%2<<endl;
}