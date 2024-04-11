#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define int long long

signed main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);

        int d=b-a;
        if(d>a){
            cout<<"NO"<<endl;
            continue;
        }
        if((a-d)%3==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}