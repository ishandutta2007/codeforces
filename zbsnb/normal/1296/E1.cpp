#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
char s[200010];
int ans[26][200010];
int p[26];
int anss[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            if(s[i]>=ans[j][p[j]]){
                ans[j][++p[j]]=s[i];
                anss[i]=j+1;
                break;
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,anss[i]);
    cout<<(maxn<=2?"YES":"NO")<<endl;
    if(maxn<=2)for(int i=1;i<=n;i++)cout<<anss[i]-1;cout<<endl;
}