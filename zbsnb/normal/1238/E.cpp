#include<iostream>
#include<algorithm>
using namespace std;
int a[20][20];
int dp[1<<20];
char s[100010];
int main(){
    int n,m;cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        a[s[i]-'a'][s[i-1]-'a']++;
        a[s[i-1]-'a'][s[i]-'a']++;
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<1<<m;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j))cnt++;
            }
            //cout<<i<<" "<<k<<endl;
            if(cnt!=k)continue;
            dp[i]=1e9;
            for(int j=0;j<m;j++){
                if((i&(1<<j))==0)continue;
                int tmp=dp[i^(1<<j)];
                for(int o=0;o<m;o++){
                    if(o==j)continue;
                    if(i&(1<<o)){
                        tmp-=a[o][j]*(m-k);
                    }
                    else{
                        tmp+=a[o][j]*(m-k);
                    }
                }
                dp[i]=min(dp[i],tmp);
                //cout<<i<<" "<<j<<" "<<tmp<<endl;
            }
            //cout<<i<<" "<<dp[i]<<endl;
        }
    }
    cout<<dp[(1<<m)-1]<<endl;
}