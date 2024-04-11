#include<iostream>
#include<vector>
#include<set>
using namespace std;
int read()        
{        
    int s = 0, f = 1;        
    char ch = getchar();        
    while(!isdigit(ch)) {        
        if(ch == '-') f = -1;        
        ch = getchar();        
    }        
    while(isdigit(ch)) {        
        s = s * 10 + ch - '0';        
        ch = getchar();        
    }        
    return s * f;        
}     
set<pair<int,int> > cho[55];
int mp[55][20005];
int main(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=read();
        }
    }

    int ans=0;
    cho[0].insert({0,-1000});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int lim=j+k-1;
            if(lim>m)break;

            int sum=0;
            for(int k=j;k<=lim;k++){
                sum+=mp[i][k]+mp[i+1][k];
            }
            int maxn=0;
            for(auto &it:cho[i-1]){
                int now=sum+it.first;
                int l=it.second,r=it.second+k-1;

                if(l>lim||r<j){
                    maxn=max(maxn,now);
                    continue;
                }

                for(int k=j;k<=lim;k++){
                    if(!(k<l||k>r))now-=mp[i][k];
                }
                maxn=max(maxn,now);
            }
            ans=max(ans,maxn);
            cho[i].insert({maxn,j});
            if(cho[i].size()>=45)cho[i].erase(cho[i].begin());
        }
    }
    cout<<ans<<endl;
}