#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int m=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
        // cout<<a[i]<<endl;
    }
    vector<pair<int,int> > ans;
    for(int i=n;i>=1;i--){
        vector<pair<int,int> > tmp;
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                tmp.push_back({a[j],j});
            }
        }
        sort(tmp.begin(),tmp.end());
        for(auto &it:tmp){
           ans.push_back({it.second,i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
}