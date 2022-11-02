#include<iostream>
#include<vector>
using namespace std;
int vis[1000010];
int ans[1000010],p=0;
int e[1000010];
int dfs(int u){
	// cout<<"now"<<" "<<u<<endl;
	if(vis[u]){
		ans[++p]=u;
		return u;
	}

	vis[u]=1;
	int tmp=dfs(e[u]);
	// cout<<u<<" "<<it<<" "<<tmp<<endl;
	if(tmp){
		if(tmp==u){
			return 0;
		}
		else{
			ans[++p]=u;
			return tmp;
		}
	}

	return 0;
};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;p=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			int tmp;cin>>tmp;
			e[i]=i-tmp;
			// cout<<"E"<<" "<<i<<" "<<i-tmp<<endl;
		}

		dfs(1);
		cout<<p<<"\n";
		for(int i=1;i<=p;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
}