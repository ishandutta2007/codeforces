#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxn[10][100010];
ll minn[10][100010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<=n;i++) {
            maxn[0][i]=minn[0][i]=1;
            for(int j=1;j<=5;j++){
                maxn[j][i]=-1e18;
                minn[j][i]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            for(int j=1;j<=min(i,5);j++){
                ll a=tmp*maxn[j-1][i-1];
                ll b=tmp*minn[j-1][i-1];

                maxn[j][i]=max(a,b);
                minn[j][i]=min(a,b);
                
                if(i>=2){
                    maxn[j][i]=max(maxn[j][i-1],maxn[j][i]);
                    minn[j][i]=min(minn[j][i-1],minn[j][i]);
                }
                // cout<<i<<" "<<j<<" "<<maxn[j][i]<<" "<<minn[j][i]<<endl;
            }
        }
        cout<<maxn[5][n]<<endl;
    }
}