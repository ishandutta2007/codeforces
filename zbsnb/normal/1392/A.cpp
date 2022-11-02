#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int flg=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++)if(a[i]!=a[i-1])flg=1;
        if(flg)cout<<1<<endl;
        else cout<<n<<endl;
    }
}