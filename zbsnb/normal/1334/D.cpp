#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// #define int long long
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;ll l,r;cin>>l>>r;
        if(l==1ll*n*(n-1)+1){
            cout<<1<<endl;
            continue;
        }
        ll m=n-1;ll tot=0;
        while(tot+2*m<l) tot+=2*m,m--;
        // cout<<m<<endl;
        ll now=l-tot;
        // cout<<"?"<<m<<" "<<now<<endl;
        vector<int> vec;
        while(1){
            for(int i=1;i<=2*m;i++){
                if(i&1) vec.push_back(n-m);
                else vec.push_back(n-m+i/2);
            }
            m--;
            if(m==0||vec.size()>=5e5) break;
        }
        int cnt=0;
        while(++cnt<=r-l+1){
            if(cnt==r-l+1&&r==1ll*n*(n-1)+1) cout<<1<<" ";
            else cout<<vec[now++-1]<<" ";
        }
        cout<<endl;
    }
}