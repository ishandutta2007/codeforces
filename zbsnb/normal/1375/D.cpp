#include<bits/stdc++.h>
using namespace std;
int a[1010], n;
multiset<int> s;
vector<int> ans;
int mex(){
    int ret=0;
    for(auto &it:s) if(it==ret) ret++;
    return ret;
}
void work(int pos,int val){
    s.erase(s.find(a[pos]));ans.push_back(pos);
    a[pos]=val;s.insert(val);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;ans.clear();s.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];s.insert(a[i]);
        }
        int m=mex();int cnt=0;
        while(m!=n){
            work(m+1,m);
            m=mex();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&a[j]==i-1){
                    work(j,mex());
                    break;
                }
            }
            if(a[i]!=i-1){
                work(i,i-1);
            }
        }
        cout<<ans.size()<<endl;
        for(auto &it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}