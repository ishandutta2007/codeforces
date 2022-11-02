#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,p;cin>>n>>p;
        vector<int> vec;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            vec.push_back(tmp);
        }
        if(p==1){
            cout<<n%2<<endl;
            continue;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        int pre=-1;
        stack<pair<int,int> > s;
        for(auto &it:vec){
            if(pre==-1) pre=it;
            else{
                auto tmp=make_pair(it,1);
                s.push(tmp);
                while(1){
                    auto tmp=s.top();s.pop();
                    if(!s.empty()&&tmp.first==s.top().first){
                        tmp.second+=s.top().second;s.pop();
                        if(tmp.second==p){
                            tmp.first++;
                            tmp.second=1;
                        }
                        s.push(tmp);
                    }
                    else{
                        s.push(tmp);
                        break;
                    }
                }
                if(s.size()==1&&s.top().first==pre){
                    pre=-1;
                    s.pop();
                }
            }
        }
        // cout<<pre<<endl;
        ll ans=pre==-1?0:mypow(p,pre);
        while(!s.empty()){
            auto tmp=s.top();s.pop();
            ans-=tmp.second*mypow(p,tmp.first)%mod;
            // cout<<tmp.first<<" "<<tmp.second<<endl;
        }
        cout<<(ans%mod+mod)%mod<<endl;
    }
}