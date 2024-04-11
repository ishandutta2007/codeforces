#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,m;cin>>n>>k>>m;
        int l=0,r=m-1;
        int flg=0;

        for(int i=1;i<=m;i++){
            int tmp;cin>>tmp;
            int L=tmp-l-1,R=(n-tmp)-r;
            // cout<<i<<" "<<L<<" "<<R<<endl;
            if(L>=k/2&&R>=k/2){
                flg=1;
            }
            l++,r--;
        }

        if(n==m){
            cout<<"YES"<<endl;
            continue;
        }
        if((n-m)%(k-1)!=0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<(flg?"YES":"NO")<<endl;
    }
}