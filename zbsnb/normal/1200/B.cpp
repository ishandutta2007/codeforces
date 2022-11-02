#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll h[110];
int main(){
    int t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        for(int i=1;i<=n;i++)cin>>h[i];
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        int flg=1;
        for(int i=1;i<n;i++){
            if(h[i+1]<=k)m+=h[i];
            else if(h[i+1]>k){
                m+=(h[i]-(h[i+1]-k));
            }
            if(m<0){
                flg=0;
                break;
            }
        }
        if(flg)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}