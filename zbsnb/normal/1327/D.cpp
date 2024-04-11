#include<iostream>
#include<vector>
using namespace std;
int a[1000100],c[1000100];
int vis[1000100];
int check(vector<int> &vec,int lim,int k){
    for(int i=0;i<k;i++){
        int flg=0;
        for(int j=i;j<lim;j+=k){
            if(c[vec[j]]!=c[vec[i]]){
                flg=1;
                break;
            }
        }
        if(flg==0) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
		for(int i=1;i<=n;i++)vis[i]=0;
        vector<vector<int> > vec;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> tmp;
                int now=i;tmp.push_back(now);
                vis[now]=1;
                while((now=a[now])!=i){
                    tmp.push_back(now);
                    vis[now]=1;
                }
                vec.push_back(tmp);
            }
        }

        int ans=1e9;
        for(auto &it:vec){
			// cout<<"now:"<<t<<endl;
            // for(auto &it2:it){
            //     cout<<it2<<" ";
            // }cout<<endl;
            int lim=it.size();
            for(int i=1;i*i<=lim;i++){
                if(lim%i==0){
                    if(check(it,lim,i))ans=min(ans,i);
                    if(check(it,lim,lim/i))ans=min(ans,lim/i);
                }
            }
        }
        cout<<ans<<"\n";
    }
}