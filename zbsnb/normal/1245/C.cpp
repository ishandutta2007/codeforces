#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll f[100010];
char s[100010];
int main(){
    f[0]=f[1]=1;
    for(int i=2;i<100010;i++)f[i]=(f[i-1]+f[i-2])%mod;
    cin>>s;
    ll ans=1;
    int cnt=1;
    int n=strlen(s);
    for(int i=0;i<=n;i++){
        if(i==n||s[i]!=s[i-1]){
            if(s[i-1]=='n'||s[i-1]=='u'){
                ans*=f[cnt];
                ans%=mod;
            }
            if(s[i-1]=='m'||s[i-1]=='w'){
                cout<<0<<endl;
                return 0;
            }
            cnt=1;
        }
        else cnt++;
    }
    cout<<ans<<endl;
}