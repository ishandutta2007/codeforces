#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans^=a[i];
        }
        if(ans==0)cout<<"DRAW"<<endl;
        else{
            int now=1;
            while((now<<1)<=ans)now<<=1;
            int cnt=0;
            for(int i=1;i<=n;i++){
                cnt+=(a[i]&now)?1:0;
            }
            cout<<(
                !((cnt/2)&1)&&(n&1)
                ||((cnt/2)&1)&&!(n&1)
                // ||((cnt/2)&1)&&(n&1)
                ||!((cnt/2)&1)&&!(n&1)
            ?"WIN":"LOSE")<<endl;
        }
    }
}