#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long

int pre[26];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
char s[1000010];
int vis[26];
signed main(){
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<26;i++)pre[i]=i;
    for(int i=1;i<=n;i++){
        cin>>s;
        int now[26]={};
        int len=strlen(s);
        for(int i=0;i<len;i++){
            now[s[i]-'a']=1;
            vis[s[i]-'a']=1;
        }

        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                if(now[i]&&now[j]){
                    pre[find(i)]=find(j);
                    // cout<<find(i)<<" "<<find(j)<<endl;
                }
            }
        }
        // for(int i=0;i<26;i++)cout<<now[i]<<" ";cout<<endl;
    }
    for(int i=0;i<26;i++)ans+=vis[i];
    for(int i=0;i<26;i++){
        // cout<<i<<" "<<find(i)<<endl;
        if(vis[i]){
            if(find(i)!=i){
                ans--;
            }
        }
    }
    cout<<ans<<endl;
}