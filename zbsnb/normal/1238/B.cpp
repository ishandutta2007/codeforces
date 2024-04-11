#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        map<int,int,greater<int> > mp;
        for(int i=1;i<=n;i++){
            int x;cin>>x;mp[x]++;
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if((it->first)<=cnt*m)break;
            cnt++;
        }
        cout<<cnt<<endl;
    }
}