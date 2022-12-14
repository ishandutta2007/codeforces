#include<bits/stdc++.h>
using namespace std;

void ask(int l,int r){
	cout<<'?'<<' '<<l<<' '<<r<<endl;
}
int n,ans[101];

void guess(){
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<char(ans[i]);
	cout<<endl;
}
int cnt[2][105];
int sum[2][105];

vector<pair<int,int> > e[105];

void dfs(int x,int p){
	for(auto it:e[x]){
		if(it.first==p)	continue;
		ans[it.first]=it.second-ans[x];
		dfs(it.first,x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1){
		ask(1,1);
		string s;
		cin>>s;
		cout<<"! "<<s<<endl;
	}
	else{
		ask(1,n);
		for(int i=0;i<n*(n+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[0][s.size()]+=(int)(it);
			}
		}
		int len=n;
		int root;
		for(int i=1;i<=(n+1)/2;i++){
			if(i==n-i+1){
				root=i;
				ans[i]=cnt[0][len]-cnt[0][len+1];
			}
			else{
				int w=(cnt[0][len]-cnt[0][len+1])-(cnt[0][len-1]-cnt[0][len]);
				e[i].emplace_back(n-i+1,w);
				e[n-i+1].emplace_back(i,w);
			}
			len--;
		}
		ask(2,n);
		for(int i=0;i<n*(n-1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[1][s.size()]+=(int)(it);
			}
		}
		len=n-1;
		for(int i=2;i<=n/2+1;i++){
			if(i==n-i+2){
				root=i;
				ans[i]=cnt[1][len]-cnt[1][len+1];
			}
			else{
				int w=(cnt[1][len]-cnt[1][len+1])-(cnt[1][len-1]-cnt[1][len]);
				e[i].emplace_back(n-i+2,w);
				e[n-i+2].emplace_back(i,w);
			}
			len--;
		}
		dfs(root,0);
		guess();
	}
}