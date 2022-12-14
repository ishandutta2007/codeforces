#include<bits/stdc++.h>
using namespace std;
// CF 508D
// Start
/* Be careful for single vertex
 * 1-based
 * return: (from, to, id)
 */
 template<int SZ,bool directed> struct Euler{
	int m=0;
	vector<pair<int,int> > e[SZ+1];vector<bool> used;
	vector<pair<int,int> >::iterator its[SZ+1];
	void addedge(int u,int v){
		e[u].emplace_back(v,m);
		if(!directed)  e[v].emplace_back(u,m);
		used.push_back(false),m++;
	}
	vector<tuple<int,int,int> > solve(int n,int s){
		for(int i=1;i<=n;i++)	its[i]=e[i].begin();
		vector<tuple<int,int,int> > res,st={{-1,s,-1}};
		while(!st.empty()){
			int x=get<1>(st.back());
			auto &it=its[x],end=e[x].end();
			while(it!=end&&used[it->second])	
				it++;
			if(it==end){
				if(res.size()&&get<0>(res.back())!=x)	
					return  {};
				res.emplace_back(st.back()),st.pop_back();
			}
			else  st.push_back({x,it->first,it->second}),used[it->second]=1;
		}
		if(res.size()!=m+1) return {};
		res.pop_back(),reverse(res.begin(),res.end());
		return res;}
};
// End

int d[4000],sz;
string inv[4000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	map<string,int> m;
	Euler<4000,true> E;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(n==1){
			cout<<"YES"<<endl;
			cout<<s<<endl;
			return 0;
		}
		string f=s.substr(0,2),t=s.substr(1,2);
		sz=m.size();
		int fid=m.count(f)?m[f]:(inv[sz+1]=f,m[f]=++sz);
		sz=m.size();
		int tid=m.count(t)?m[t]:(inv[sz+1]=t,m[t]=++sz);
		E.addedge(fid,tid);
		d[fid]++;
		d[tid]--;
	}
	int c1=0,r=1;
	for(int i=1;i<=sz;i++){
		if(d[i]>1||d[i]<-1){
			cout<<"NO"<<endl;
			return 0;
		}
		if(d[i]==1)	c1++,r=i;
	}
	if(c1>1){
		cout<<"NO"<<endl;
		return 0;
	}
	auto res=E.solve(sz,r);
	if(res.size()==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<inv[get<0>(res[0])];
	for(int i=0;i<n;i++)
		cout<<inv[get<1>(res[i])][1];
	cout<<endl;
}