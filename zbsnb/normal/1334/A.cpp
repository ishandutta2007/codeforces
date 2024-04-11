#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int pre1=0,pre2=0;
        int flg=0;
        for(int i=1;i<=n;i++){
            int tmp1,tmp2;cin>>tmp1>>tmp2;
            if(tmp1<pre1){
                flg=1;
            }
            if(tmp2<pre2){
                flg=1;
            }
            if(tmp1-pre1<tmp2-pre2){
                flg=1;
            }
            pre1=tmp1;
            pre2=tmp2;
        }
        cout<<(flg?"NO":"YES")<<endl;
    }
}