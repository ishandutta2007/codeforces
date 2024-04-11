#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int minn=1e9;
        for(int i=1;i<=n;i++){
            cin>>a[i];b[i]=0;
            minn=min(minn,a[i]);
        }
        vector<int> tmp;
        for(int i=1;i<=n;i++){
            if(a[i]%minn!=0)b[i]=a[i];
            else tmp.push_back(a[i]);
        }
        sort(tmp.begin(),tmp.end());
        int now=0;
        for(int i=1;i<=n;i++){
            if(b[i]==0) b[i]=tmp[now++];
            // cout<<i<<" "<<b[i]<<endl;
        }
        int flg=0;
        for(int i=2;i<=n;i++){
            if(b[i]<b[i-1]){
                // cout<<"?"<<i<<endl;
                flg=1;
                break;
            }
        }
        cout<<(!flg?"YES":"NO")<<endl;
    }
}