#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > vec;
void dfs(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1,d=(r-l+1)>>1;
    dfs(l,mid);
    dfs(mid+1,r);
    for(int i=l;i<=mid;i++){
        vec.push_back({i,i+d});
    }
}
int main(){
    int n;cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int k=31-__builtin_clz(n);
    int cnt=1<<k;
    // cout<<n<<" "<<cnt<<endl;
    dfs(1,cnt);
    dfs(n-cnt+1,n);
    cout<<vec.size()<<endl;
    for(auto &it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
}