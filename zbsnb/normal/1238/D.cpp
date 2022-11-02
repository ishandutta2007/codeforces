#include<iostream>
using namespace std;
#define ll long long 
int a[300010],b[300010];
int main(){
    int n;cin>>n;
    char s[300010];cin>>s+1;
    ll ans=1ll*n*(n-1)/2;
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1])cnt++;
        else{
            ans-=cnt;
            cnt=1;
        }
    }
    cnt=1;
    for(int i=n-1;i>=1;i--){
        if(s[i]==s[i+1])cnt++;
        else{
            ans-=cnt;
            cnt=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(s[i]!=s[i-1])ans++;
    }
    cout<<ans<<endl;
}