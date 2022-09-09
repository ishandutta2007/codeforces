#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int k,n,m,i,j,a[N],tp[N],b;
pair<int,int>o1[N];
vector<pair<int,int>>o2[N],o3[N];
vector<pair<double,int>>op1[N],op2[N];
vector<double>ps1[N],ps2[N],ps0[N];int len[N];
vector<int>ans;
bool cmp1(int x,int y){return tp[x]<tp[y];}
inline void work(vector<double>&a,const vector<pair<double,int>>&b){
	a.resize(b.size());for(int i=0;i<a.size();++i)a[i]=b[i].first+(i?a[i-1]:0);
}
priority_queue<pair<double,int>>q;
inline void ins(const vector<pair<double,int>>&v,int l){for(int i=0;i<l;++i)ans.push_back(v[i].second);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>k>>n>>m;
	for(i=1;i<=k;++i)cin>>a[i];
	for(j=1;j<=n;++j){
		cin>>tp[j]>>i>>b;
		if(tp[j]==1)o1[i]=max(o1[i],make_pair(b,j));
		if(tp[j]==2)o2[i].push_back(make_pair(b,j));
		if(tp[j]==3 && b>1)o3[i].push_back(make_pair(b,j));
	}
	for(i=1;i<=k;++i){
		sort(o2[i].begin(),o2[i].end(),greater<pair<int,int>>());
		sort(o3[i].begin(),o3[i].end(),greater<pair<int,int>>());
		for(auto u:o3[i])op1[i].push_back(make_pair(log(u.first),u.second));
		long long s=a[i];
		for(auto u:o2[i])op1[i].push_back(make_pair(log(1+u.first*1.0/s),u.second)),s+=u.first;
		sort(op1[i].begin(),op1[i].end(),greater<pair<double,int>>());
		if(o1[i].first>a[i]){
			op2[i]={make_pair(log(o1[i].first*1.0/a[i]),o1[i].second)};
			for(auto u:o3[i])op2[i].push_back(make_pair(log(u.first),u.second));
			s=o1[i].first;
			for(auto u:o2[i])op2[i].push_back(make_pair(log(1+u.first*1.0/s),u.second)),s+=u.first;
			sort(op2[i].begin(),op2[i].end(),greater<pair<double,int>>());
		}
		work(ps1[i],op1[i]);work(ps2[i],op2[i]);
		ps0[i].resize(max(ps1[i].size(),ps2[i].size()));
		for(j=0;j<ps0[i].size();++j)ps0[i][j]=max(j<ps1[i].size()?ps1[i][j]:0,j<ps2[i].size()?ps2[i][j]:0);
		if(!ps0[i].empty())len[i]=0,q.push(make_pair(ps0[i][0],i));
	}
	for(j=1;j<=m && !q.empty();++j){
		auto u=q.top();q.pop();i=u.second;
		if(++len[i]<ps0[i].size())q.push(make_pair(ps0[i][len[i]]-ps0[i][len[i]-1],i));
	}
	for(i=1;i<=k;++i)ins(len[i]<=ps1[i].size() && len[i]>0 && ps0[i][len[i]-1]==ps1[i][len[i]-1]?op1[i]:op2[i],len[i]);
	sort(ans.begin(),ans.end(),cmp1);
	cout<<ans.size()<<'\n';for(int x:ans)cout<<x<<' ';cout<<endl;
	return 0;
}