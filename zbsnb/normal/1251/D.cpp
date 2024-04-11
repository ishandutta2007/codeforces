#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define ll long long

int l[200010];
int r[200010];
int n;ll k;
bool pd(int x){
    multiset<int> s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(r[i]>=x){
            if(x>=l[i])s.insert(x-l[i]);
            else cnt++;
        }
    }
    ll ans=k;
    for(auto it=s.begin();it!=s.end();it++){
        if(cnt>=n/2+1)break;
        ans-=*it;
        cnt++;
    }
    //cout<<x<<" "<<ans<<" "<<cnt<<endl;
    return ans>=0&&cnt>=n/2+1;
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>l[i]>>r[i];
            k-=l[i];
        }
        int l=1,r=1e9;
        int ans=0;
        while(l<=r){
            int m=l+r>>1;
            if(pd(m)){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        cout<<ans<<endl;
    }
}