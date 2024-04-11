#include<bits/stdc++.h>
using namespace std;

set<int> s;
int a[100000],b[100000],p[200001],deg[200001];
map<int,int> m;
vector<int> ans,edge[200001];
void dfs(int x){
	while(edge[x].size()){
		int tmp=edge[x].back();
		edge[x].pop_back();
		edge[tmp].erase(find(edge[tmp].begin(),edge[tmp].end(),x));
		dfs(tmp);
	}
	ans.push_back(x);
}
int stp=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
		cin>>a[i],s.insert(a[i]);
	for(int i=0;i<n-1;i++)
		cin>>b[i],s.insert(b[i]);
	for(int i=0;i<n-1;i++)
		if(a[i]>b[i]){
			cout<<-1<<endl;
			return 0;
		}
	for(auto i:s)
		m[i]=++stp,p[stp]=i;
	for(int i=0;i<n-1;i++)
		a[i]=m[a[i]],b[i]=m[b[i]];
	for(int i=0;i<n-1;i++){
		deg[a[i]]++;edge[a[i]].push_back(b[i]);
		deg[b[i]]++;edge[b[i]].push_back(a[i]);
	}
	int f=1,cnt=0;
	for(int i=1;i<=stp;i++){
		if(deg[i]&1){
			f=i;cnt++;
		}
		sort(edge[i].begin(),edge[i].end());
	}
	if(cnt!=2&&cnt!=0){
		cout<<-1<<endl;
		return 0;
	}
	dfs(f);
	if(ans.size()!=n){
		cout<<-1<<endl;
	}
	else{
		for(int i:ans)
			cout<<p[i]<<' ';
		cout<<endl;
	}
	

}