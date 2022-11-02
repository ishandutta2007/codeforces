#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> ans;
int g,h;
int a[5000010];
int dfs(int rt,int op){
	int ls=rt<<1;
	int rs=(rt<<1)|1;
	if(a[ls]==0&&a[rs]==0){
		if(rt>=1<<g){
			a[rt]=0;
			ans.push_back(op);
			return 1;
		}
		else return 0;
	}
	else{
		if(a[ls]>a[rs]){
			int tmp=a[ls];
			if(dfs(ls,op)){
				a[rt]=tmp;
				return 1;
			}
			else return 0;
		}
		else{
			int tmp=a[rs];
			if(dfs(rs,op)){
				a[rt]=tmp;
				return 1;
			}
			else return 0;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>h>>g;ans.clear();
		for(int i=1;i<(1<<(h+1));i++) a[i]=0;
		for(int i=1;i<(1<<h);i++){
			cin>>a[i];
		}
		priority_queue<pair<int,int> > q;
		q.push({a[1],1});
		for(int i=1;i<=((1<<h)-(1<<g));i++){
			while(1){
				auto ind=q.top().second;q.pop();
				// cout<<ind<<endl;
				if(dfs(ind,ind)){
					q.push({a[ind],ind});
					break;
				}
				else{
					q.push({a[ind<<1],ind<<1});
					q.push({a[(ind<<1)|1],(ind<<1)|1});
				}
			}
			// for(int i=1;i<(1<<h);i++) cout<<a[i]<<" ";
			// cout<<endl;
		}
		
		ll ans_ans=0;
		for(int i=1;i<(1<<g);i++){
			ans_ans+=a[i];
		}
 
		cout<<ans_ans<<endl;
		for(auto &it: ans){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	
}