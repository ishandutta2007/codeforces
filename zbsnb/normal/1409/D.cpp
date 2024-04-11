#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        unsigned int n,s;cin>>n>>s;
        unsigned int now=n;
        for(unsigned int i=1;i<=1e19+10;i*=10){
            unsigned int tot=0;
            unsigned int tmp=now;
            while(tmp){
                tot+=tmp%10;
                tmp/=10;
            }
            if(tot<=s) break;
            while(now/i%10) now+=i;
        }
        // cout<<now<<" "<<n<<endl;
        cout<<(now-n)<<endl;
    }
}