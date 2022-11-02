#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
#define ll long long

int a[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int flg=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            a[i]-=tmp;
            if(a[i]>0)flg=1;
        }
        if(flg){
            cout<<"NO"<<endl;
            continue;
        }

        flg=0;
        int pre=1;
        for(int i=1;i<=n;i++){
            //cout<<i<<" "<<pre<<endl;
            if(a[i]){
                if(pre!=1&&a[i]!=pre){
                    flg=3;
                    break;
                }
                pre=a[i];
                if(flg==2){
                    flg=3;
                    break;
                }
                else flg=1;
            }
            else{
                if(flg)flg=2;
            }
        }

        if(flg==3)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}