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
int cnt[3][105];
int sum[2][105];

vector<pair<int,int> > e[105];

void dfs(int x){
	for(auto it:e[x]){
		if(ans[it.first]!=-1)	continue;
		ans[it.first]=it.second-ans[x];
		dfs(it.first);
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
	else if(n==2){
		ask(1,1);
		string s1;
		cin>>s1;
		ask(2,2);
		string s2;
		cin>>s2;
		cout<<"! "<<s1<<s2<<endl;
	}
	else if(n&1){
		memset(ans,-1,sizeof ans);
		ask(1,n);
		int len=n;
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[0][s.size()]+=(int)(it);
			}
		}
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
		int N=n/2;
		len=N;
		ask(1,N);
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[1][s.size()]+=(int)(it);
			}
		}
		for(int i=1;i<=(N+1)/2;i++){
			if(i==N-i+1){
				root=i;
				ans[i]=cnt[1][len]-cnt[1][len+1];
			}
			else{
				int w=(cnt[1][len]-cnt[1][len+1])-(cnt[1][len-1]-cnt[1][len]);
				e[i].emplace_back(N-i+1,w);
				e[N-i+1].emplace_back(i,w);
			}
			len--;
		}
		N=n/2+1;
		len=n-N+1;
		ask(n-N+1,n);
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[2][s.size()]+=(int)(it);
			}
		}
		for(int i=1;i<=((n-N+1)+1)/2;i++){
			if(N+i-1==n+N-(N+i-1)){
				root=N+i-1;
				ans[N+i-1]=cnt[2][len]-cnt[2][len+1];
			}
			else{
				int w=(cnt[2][len]-cnt[2][len+1])-(cnt[2][len-1]-cnt[2][len]);
				e[N+i-1].emplace_back(n+N-(N+i-1),w);
				e[n+N-(N+i-1)].emplace_back(N+i-1,w);
			}
			len--;
		}
		dfs(root);
		guess();
	}
	else{
		memset(ans,-1,sizeof ans);
		ask(1,n);
		int len=n;
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[0][s.size()]+=(int)(it);
			}
		}
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
		int N=n/2;
		len=N;
		ask(1,N);
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[1][s.size()]+=(int)(it);
			}
		}
		for(int i=1;i<=(N+1)/2;i++){
			if(i==N-i+1){
				root=i;
				ans[i]=cnt[1][len]-cnt[1][len+1];
			}
			else{
				int w=(cnt[1][len]-cnt[1][len+1])-(cnt[1][len-1]-cnt[1][len]);
				e[i].emplace_back(N-i+1,w);
				e[N-i+1].emplace_back(i,w);
			}
			len--;
		}
		N=n/2+2;
		len=n-N+1;
		ask(N,n);
		for(int i=0;i<len*(len+1)/2;i++){
			string s;
			cin>>s;
			for(char it:s){
				cnt[2][s.size()]+=(int)(it);
			}
		}
		for(int i=1;i<=((n-N+1)+1)/2;i++){
			if(N+i-1==n+N-(N+i-1)){
				root=N+i-1;
				ans[N+i-1]=cnt[2][len]-cnt[2][len+1];
			}
			else{
				int w=(cnt[2][len]-cnt[2][len+1])-(cnt[2][len-1]-cnt[2][len]);
				e[N+i-1].emplace_back(n+N-(N+i-1),w);
				e[n+N-(N+i-1)].emplace_back(N+i-1,w);
			}
			len--;
		}
		dfs(root);
		guess();
	}
}