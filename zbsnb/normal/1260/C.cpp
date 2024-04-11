#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define int long long

int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b,k;cin>>a>>b>>k;
        if(a>b)swap(a,b);
        if(a==b){
            cout<<"OBEY"<<endl;
            continue;
        }
        // cout<<gcd(a,b)<<endl;
        int ans=(b-gcd(a,b)-1)/a+1;
        // cout<<ans<<endl;
        cout<<(ans<k?"OBEY":"REBEL")<<endl;
    }
}