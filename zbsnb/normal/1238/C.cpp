#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        map<int,int,greater<int> > a;
        int ans=0;
        for(int i=1;i<=m;i++){
            int tmp;cin>>tmp;
            a[tmp]=1;
        }
        a[0]=1;
        int cnt=0;
        int pre=n;
        for(auto it=++a.begin();it!=a.end();it++){
            //cout<<it->first<<endl;
            if(it->first+1==pre)cnt++;
            else {
                if(cnt%2)ans++;
                cnt=1;
            }
            pre=it->first;
        }
        cout<<ans<<endl;
    }
}