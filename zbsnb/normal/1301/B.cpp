#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int> a;
        int n;cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            cnt+=tmp==-1;
            a.push_back(tmp);
        }
        if(cnt==n){
            cout<<"0 0"<<endl;
            continue;
        }
        int minn=1e9,maxn=0;
        int ans=0;
        for(int i=1;i<a.size();i++){
            if(a[i-1]==-1&&a[i]!=-1){
                minn=min(minn,a[i]);
                maxn=max(maxn,a[i]);
            }
            if(a[i]==-1&&a[i-1]!=-1){
                minn=min(minn,a[i-1]);
                maxn=max(maxn,a[i-1]);
            }
            if(a[i]!=-1&&a[i-1]!=-1){
                ans=max(ans,abs(a[i]-a[i-1]));
            }
        }
        int tmp=(minn+maxn)/2;
        cout<<max(max(maxn-tmp,tmp-minn),ans)<<" "<<tmp<<"\n";
    }
}