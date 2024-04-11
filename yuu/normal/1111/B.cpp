#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int a[100001];
int main(){
    cin>>n>>k>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    long double ans=0;
    long double sum=0;
    for(int i=1; i<=n; i++){
        sum+=a[i];
        if(n-i>m) continue;
        else ans=max(ans, (sum+min((long double)m-(n-i), ((long double)i)*k))/i);
    }
    cout<<setprecision(16)<<fixed<<ans;
}