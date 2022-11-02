#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        ll low=max((1ll<<(m-1))-105,0ll);
        ll up=min((1ll<<(m-1))+104,(1ll<<m)-1);
        set<ll> st;
        for(ll i=low;i<=up;i++)st.insert(i);
        for(int i=1;i<=n;i++){
            string s;cin>>s;
            ll tmp=0;
            for(auto &it:s){
                tmp*=2;
                tmp+=it-'0';
            }
            if(st.count(tmp))st.erase(tmp);
            else{
                if(tmp>up)st.insert(--low);
                if(tmp<low)st.insert(++up);
            }
        }
        int cnt=0,aim=(int(st.size())-1)/2;
        ll ans=0;
        for(auto &it:st){
            if(cnt==aim){
                ans=it;
                break;
            }
            cnt++;
        }
        for(int i=m-1;i>=0;i--){
            cout<<bool(ans&(1ll<<i));
        }
        cout<<endl;
    }
}