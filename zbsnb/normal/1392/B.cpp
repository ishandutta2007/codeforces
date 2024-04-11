#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;ll k;cin>>n>>k;
        int flg=0;
        int maxn=-1e9,minn=1e9;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
        }
        if(k%2){
            for(int i=1;i<=n;i++){
                cout<<(maxn-a[i])<<" ";
            }
            cout<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                cout<<(a[i]-minn)<<" ";
            }
            cout<<endl;
        }
    }
}