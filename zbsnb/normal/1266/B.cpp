#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
// #define int long long

char s[1000010];
int a[1000010];
int b[1000010];

signed main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n>=15&&(n%14>=1&&n%14<=6)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}