#include<bits/stdc++.h>
using namespace std;
int pre[1000010];
char mp[1010][1010];
int vis[2][1010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
#define pos(i,j) ((i-1)*m+j)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>mp[i]+1;
    for(int i=1;i<=n;i++) vis[0][i]=0;
    for(int j=1;j<=m;j++) vis[1][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#'&&(i==1||mp[i-1][j]=='.')) vis[1][j]++;
            if(mp[i][j]=='#'&&(j==1||mp[i][j-1]=='.')) vis[0][i]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[0][i]>=2){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int j=1;j<=m;j++){
        // cout<<j<<" "<<vis[1][j]<<endl;
        if(vis[1][j]>=2){
            cout<<-1<<endl;
            return 0;
        }
    }

    for(int i=1;i<=n;i++) vis[0][i]=0;
    for(int j=1;j<=m;j++) vis[1][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#'){
                vis[0][i]=1;
                vis[1][j]=1;
            }
            pre[pos(i,j)]=pos(i,j);
        }
    }
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)cnt0+=vis[0][i];
    for(int i=1;i<=m;i++)cnt1+=vis[1][i];
    if(cnt0==n&&cnt1!=m||cnt0!=n&&cnt1==m){
        // cout<<cnt0<<" "<<cnt1<<endl;
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#'){
                if(i!=1&&mp[i-1][j]=='#'){
                    // cout<<"u"<<find(pos(i,j))<<" "<<find(pos(i-1,j))<<endl;
                    pre[find(pos(i,j))]=find(pos(i-1,j));
                }
                if(j!=1&&mp[i][j-1]=='#'){
                    // cout<<"u"<<find(pos(i,j))<<" "<<find(pos(i,j-1))<<endl;
                    pre[find(pos(i,j))]=find(pos(i,j-1));
                }
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#'&&find(pos(i,j))==pos(i,j)){
                ans++;
            }
        }
    }

    cout<<ans<<endl;

}