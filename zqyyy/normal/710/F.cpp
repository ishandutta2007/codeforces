#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+7;
struct AC{
	int tot;
	vector<int>t[26],fail,cnt;
	inline void init(){
		tot=0,cnt.resize(1),fail.resize(1),cnt[0]=fail[0]=0;
		for(int i=0;i<26;i++)t[i].resize(1),t[i][0]=0;
	}
	inline int new_node(){
		cnt.push_back(0),fail.push_back(0);
		for(int i=0;i<26;i++)t[i].push_back(0);
		return ++tot;
	}
	inline void insert(string s){
		int u=0;
		for(int i=0;i<(int)s.size();i++){
			int c=s[i]-'a';
			if(!t[c][u]){
				int x=new_node();
				t[c][u]=x;
			}
			u=t[c][u];
		}
		cnt[u]++;
	}
	inline void build(){
		queue<int>q;
		for(int i=0;i<26;i++)
			if(t[i][0])q.push(t[i][0]);
		while(!q.empty()){
			int x=q.front();q.pop(),cnt[x]+=cnt[fail[x]];
			for(int i=0;i<26;i++)
				if(t[i][x])fail[t[i][x]]=t[i][fail[x]],q.push(t[i][x]);
				else t[i][x]=t[i][fail[x]];
		}
	}
	inline ll query(string s){
		ll res=0;
		for(int i=0,u=0;i<(int)s.size();i++)u=t[s[i]-'a'][u],res+=cnt[u];
		return res;
	}
}T[19][2];
vector<string>vec[19][2];
inline void insert(string s,int o){
	for(int i=0;i<=18;i++)
		if(vec[i][o].empty()){
			for(int j=0;j<i;j++){
				T[j][o].init();
				for(auto S:vec[j][o])T[i][o].insert(S),vec[i][o].push_back(S);
				vec[j][o].clear();
			}
			T[i][o].insert(s),vec[i][o].push_back(s),T[i][o].build();
			assert((int)vec[i][o].size()==(1<<i));
			break;
		}
}
inline ll query(string s){
	ll ans=0;
	for(int i=0;i<=18;i++){
		if(!vec[i][0].empty())ans+=T[i][0].query(s);
		if(!vec[i][1].empty())ans-=T[i][1].query(s);
	}
	return ans;
}
int n;
string s;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=18;i++)T[i][0].init(),T[i][1].init();
	while(n--){
		int opt;cin>>opt>>s;
		if(opt<=2)insert(s,opt-1);
		else cout<<query(s)<<endl;
	}
	return 0;
}