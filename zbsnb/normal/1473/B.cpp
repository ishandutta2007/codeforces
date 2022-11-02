#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string s,t;cin>>s>>t;
        string now;
        int flg=0;
        for(int i=1;i<=int(t.size());i++){
            now+=s;
            // cout<<i<<" "<<now<<endl;
            int flg2=int(now.size())%int(t.size())!=0;
            for(int i=0;i<int(now.size());i++){
                if(now[i]!=t[i%int(t.size())]){
                    flg2=1;
                    break;
                }
            }
            if(flg2==0){
                cout<<now<<endl;
                flg=1;
                break;
            }
        }
        if(flg==0) cout<<"-1"<<endl;
    }
}