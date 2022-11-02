#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        stack<int> s;
        ll ans=0;int maxn=0;
        for(int i=1;i<=n;i++){
            if(!s.empty()){
                if(maxn>a[i]&&a[i]>s.top()) ans+=a[i]-s.top();
                if(a[i]>=maxn) ans+=maxn-s.top();
            }
            while(!s.empty()&&a[i]>s.top()){
                s.pop();
            }
            s.push(a[i]);maxn=max(maxn,a[i]);
        }
        if(!s.empty()){
            ans+=maxn-s.top();
        }
        cout<<ans<<endl;
    }
}