#include<iostream>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int mp[1010][1010];
int main() {
	int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        for(int j=1;j<=tmp;j++){
            mp[i][j]=1;
        }
        mp[i][tmp+1]=2;
    }
    for(int j=1;j<=m;j++){
        int tmp;cin>>tmp;
        for(int i=1;i<=tmp;i++){
            if(mp[i][j]==2){
                cout<<0<<endl;
                return 0;
            }
            mp[i][j]=1;
        }
        if(mp[tmp+1][j]==1){
            cout<<0<<endl;
            return 0;
        }
        mp[tmp+1][j]=2;
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==0)ans=ans*2%mod;
        }
    }
    cout<<ans<<endl;

}