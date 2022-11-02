#include<iostream>
using namespace std;
#define int long long
// char s[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,a,b;cin>>n>>a>>b;
        int tmp=n-n/2;
        int c=(tmp/a)*(a+b)+tmp%a;
        if(tmp%a==0){
            int tmp1=tmp/a;
            c=tmp1*a+b*(tmp1-1);
        }
        cout<<max(n,c)<<endl;
    }
}