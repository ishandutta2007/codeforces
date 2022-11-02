#include<iostream>
#include<vector>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int u=m,d=m;
        int pre=0;

        int flg=0;
        for(int i=1;i<=n;i++){
            int t,a,b;cin>>t>>a>>b;
            int tmp=t-pre;
            pre=t;

            u+=tmp;
            d-=tmp;

            if(u<a||d>b){
                flg=1;
            }

            u=min(u,b);
            d=max(d,a);
            // cout<<i<<" "<<u<<" "<<d<<endl;
        }
        if(!flg)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}