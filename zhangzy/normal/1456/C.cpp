#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[1001000];
ll tot, ans, bas;

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=n;i>=1;--i){
        bas+=tot;
        tot+=a[i];
    }
    ans=bas;
    int c=0;
    for (int i=1;i<=n;++i){
        tot-=a[i];
        if (i%(m+1)==0){
            
        }else{
            bas+=c*a[i];
            bas-=tot;
        }
        ans=max(ans,bas);
    }
    cout<<ans<<endl;
}