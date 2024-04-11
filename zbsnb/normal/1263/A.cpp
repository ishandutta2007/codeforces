#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define ll long long

signed main(){
    int t;cin>>t;
    while(t--){
        int a[3];cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]>=a[2]){
            cout<<(a[0]+a[1]+a[2])/2<<endl;
        }
        else{
            cout<<a[0]+a[1]<<endl;
        }
    }
}