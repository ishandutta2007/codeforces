#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100010];
int b[100010];
int vis[100010];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        a[tmp]=i;
    }
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        b[i]=a[tmp];
    }
    int now=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(b[i]>now)ans++;
        vis[b[i]]=1;
        while(vis[now]==1)now++;
    }
    cout<<ans<<endl;
}