#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int n, m, f[2][2020][2020][2][2];
char s[2][2020], t[2020];
int lcp[2][2020][2020], rlcp[2][2020][2020];

int F(int c,int i,int l,int fl,int dir){
    if (l>m) return 1;
    if (s[c][i]!=t[l]||i<1||i>n) return 0;
    if (l==m) return 1;
    int &ans=f[c][i][l][fl][dir];
    if (ans!=-1) return ans;
    ans=0;
    if (!fl) ans=(ans+F(c^1,i,l+1,1,dir))%mod;
    if (!fl&&(m-l+1)%2==0&&(m-l+1)>=4){
        int las=m-l+1;
        if (dir&&lcp[c][i][l]>=las/2&&rlcp[c^1][i+las/2-1][l+las/2]>=las/2) ans=(ans+1)%mod;
        if (!dir&&rlcp[c][i][l]>=las/2&&lcp[c^1][i-las/2+1][l+las/2]>=las/2) ans=(ans+1)%mod;
    }
    if (dir) ans=(ans+F(c,i+1,l+1,0,dir))%mod;
    else ans=(ans+F(c,i-1,l+1,0,dir))%mod;
    return ans;
}

int dfs(int c,int i,int l,int si){
    if (l>m) return 1;
    if (s[c][i]!=t[l]||i<1||i>n) return 0;
    if (l==m) return 1;
    int ans=0;
    if (si==i){
        ans=(ans+F(c^1,i,l+1,1,0))%mod;
        if (l+1<m) ans=(ans+F(c^1,i,l+1,1,1))%mod;
        ans=(ans+dfs(c,i-1,l+1,si))%mod;
        ans=(ans+dfs(c,i+1,l+1,si))%mod;
    }else{
        if (si<i){
            ans=(ans+dfs(c,i+1,l+1,si))%mod;
            ans=(ans+F(c^1,i,l+1,1,1))%mod;
            if (m-l>=2&&rlcp[c^1][i][l+1]>=min(i-si+1,m-l)){
                ans=(ans+F(c^1,si,l+i-si+1,1,0))%mod;
            }
        }else{
            ans=(ans+dfs(c,i-1,l+1,si))%mod;
            ans=(ans+F(c^1,i,l+1,1,0))%mod;
            if (m-l>=2&&lcp[c^1][i][l+1]>=min(si-i+1,m-l)){
                ans=(ans+F(c^1,si,l+si-i+1,1,1))%mod;
            }
        }
    }
    //printf("%d %d %d :: %d\n",c,i,l,ans);
    return ans;
}

int main(){
    memset(f,-1,sizeof f);
    cin>>s[0]+1>>s[1]+1>>t+1;
    n=strlen(s[0]+1); m=strlen(t+1);
    for (int c=0;c<=1;++c){
        for (int i=n;i>=1;--i)
            for (int j=m;j>=1;--j)
                lcp[c][i][j]= s[c][i]==t[j]? lcp[c][i+1][j+1]+1: 0; 
        for (int i=1;i<=n;++i)
            for (int j=m;j>=1;--j)
                rlcp[c][i][j]= s[c][i]==t[j]? rlcp[c][i-1][j+1]+1: 0;
    }
    int ans=0;
    for (int c=0;c<=1;++c)
        for (int i=1;i<=n;++i){
            ans=(ans+dfs(c,i,1,i))%mod;
            //printf(" %d %d %d\n",c,i,dfs(c,i,1,i));
        }
    cout<<ans<<endl;
}