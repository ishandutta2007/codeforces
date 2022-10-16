#include <bits/stdc++.h>
using namespace std;
string s;
int n;
const int base=999727999;
int f[100001];
int p[100001];
int get_hash(int u, int v){
	return ((((long long)-p[v-u+1])*f[u-1]+f[v])%base+base)%base;
}
int makehash(string &s){
	int hs=0;
	for(auto c: s) hs=(131LL*hs+c)%base;
	return hs;
}
vector <int> ans;
class query{
public:
	int id, k;
	string m;
	vector <int> pos;
	void input(int id){
		this->id=id;
		cin>>k>>m;
	}
	void process(){
		if(pos.size()<k) ans[id]=-1;
		else{
			ans[id]=1e9;
			for(int i=k-1; i<pos.size(); i++) ans[id]=min(ans[id], (int)(pos[i]-pos[i-k+1]+m.size()));
		}
	}
};
vector <query> q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s>>n;
	s='0'+s;
	q.resize(n);
	for(int i=0; i<n; i++) q[i].input(i);
	sort(q.begin(), q.end(), [](query A, query B){
		return A.m.size()<B.m.size();
	});
	ans.resize(n);
	for(int i=1; i<s.size(); i++){
		f[i]=(131LL*f[i-1]+s[i])%base;
		// cerr<<f[i]<<'\n';
	}
	p[0]=1;
	for(int i=1; i<s.size(); i++) p[i]=(131LL*p[i-1])%base;
	for(int i=0, j; i<n; i++){
		j=i;
		while((j+1<n)&&(q[j+1].m.size()==q[j].m.size())) j++;
		map <int, int> M;
		for(int k=i; k<=j; k++) M[makehash(q[k].m)]=k;
		// for(auto &x: M) cerr<<x.first<<' '<<x.second<<'\n';
		for(int k=q[i].m.size(); k<s.size(); k++){
			int hs=get_hash(k-q[i].m.size()+1, k);
			// cerr<<hs<<'\n';
			auto res=M.find(hs);
			if(res!=M.end()) q[res->second].pos.push_back(k);
		}
		i=j;
	}
	for(int i=0; i<n; i++) q[i].process();
	for(int i=0; i<n; i++) cout<<ans[i]<<'\n';
}