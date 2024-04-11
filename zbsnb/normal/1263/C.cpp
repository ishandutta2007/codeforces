#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define ll long long

int ans[100000];

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int p=0;
        for(int i=1,j;i<=n;i=j+1){
            j=n/(n/i);
            ans[p++]=n/i;
        }
        cout<<p+1<<endl;
        cout<<0<<" ";
        for(int i=p-1;i>=0;i--)cout<<ans[i]<<" ";
        cout<<endl;
    }
}