#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
using namespace std;
#define ll long long
#define int long long

char s[1000010];
bool vis[26];
signed main(){
    int n,k;cin>>n>>k>>s;
    for(int i=1;i<=k;i++){
        char tmp;cin>>tmp;
        vis[tmp-'a']=1;
    }
    int cnt=0;
    ll ans=0;
    for(int i=0;i<=n;i++){
        if(i!=n&&vis[s[i]-'a'])cnt++;
        else ans+=cnt*(cnt+1)/2,cnt=0;
    }
    cout<<ans<<endl;
}