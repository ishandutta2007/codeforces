#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int main(){
    long long f0=1e9;
    long long f1=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a;
        long long g1=min(f1+abs(a-1), f0+abs(a+1));
        long long g0=min(f0+abs(a-1), f1+abs(a+1));
        f0=g0;
        f1=g1;
    }
    cout<<f1<<'\n';
}