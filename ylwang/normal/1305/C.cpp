#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],s[maxn];
ll ans=1;
int main(){
    cin>>n>>m;
    if(n<=m){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=(ans*abs(a[j]-a[i])%m)%m;
        cout<<ans;
    }
    else
        cout<<"0";
    return 0;
}