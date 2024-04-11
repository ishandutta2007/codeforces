#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    long long sum=accumulate(a+1, a+n+1, 0LL);
    long long mx=*max_element(a+1, a+n+1);
    cout<<setprecision(10)<<fixed<<(double(sum-mx))/(n-1)+mx<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}