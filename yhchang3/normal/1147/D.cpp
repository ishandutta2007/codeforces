#include<bits/stdc++.h>
using namespace std;


struct DSU{
	vector<int> sz,p;
	void init(int n){
		sz.resize(n);p.resize(n);
		for(int i=0;i<n;i++)
			sz[p[i]=i]=1;
	}
	int F(int x){
		return x==p[x]?x:p[x]=F(p[x]);
	}
	bool U(int x,int y){
		x=F(x),y=F(y);
		if(x==y)	return false;
		if(sz[x]<sz[y])
			swap(x,y);
		p[y]=x;
		sz[x]+=sz[y];
		return true;
	}
};

vector<int> e[3000];
int c[3000];

const int mod = 998244353;
bool dfs(int x){
	for(int it:e[x])
		if(c[it]){
			if(c[x]+c[it]!=3)	return false;
		}
		else{
			c[it]=3-c[x];
			if(!dfs(it))
				return false;
		}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int m=s.size();
	s.insert(0," ");
	long long int ans=0;
	for(int i=1;i<=m;i++){
		DSU D;
		D.init(2+m+i);
		vector<pair<int,int> > v;
		v.emplace_back(0,1);
		D.U(1,2+m);
		D.U(1,2);
		for(int j=0;j<2+m+i;j++)
			e[j].clear();
		for(int j=2,k=1+m;j<k;j++,k--)
			D.U(j,k);
		for(int j=2+m,k=1+m+i;j<k;j++,k--)
			D.U(j,k);
		for(int j=1;j<=m;j++){
			if(j+i>m){
				if(s[j]=='1')
					v.emplace_back(j+1,i+j+1);
				else if(s[j]=='0')
					D.U(j+1,i+j+1);
			}
			else{
				if(s[j]=='1')
					D.U(1,j+1);
				else if(s[j]=='0')
					D.U(0,j+1);
			}
		}
		for(int j=0;j<2+m+i;j++)
			c[j]=0;
		for(auto it:v){
			e[D.F(it.first)].emplace_back(D.F(it.second));
			e[D.F(it.second)].emplace_back(D.F(it.first));
		}
		bool ok=true;
		for(int j=0;j<2+m+i;j++)
			if(!c[j]){
				c[j]=1;
				ok&=dfs(j);
			}
		if(!ok)	continue;
		for(auto it:v)
			D.U(it.first,it.second);
		int cnt=0;
		for(int j=0;j<i+m+2;j++)
			if(D.F(j)==j)
				cnt++;
		long long int tmp=1;
		for(int j=1;j<cnt;j++)
			tmp=tmp*2%mod;
		ans+=tmp;
	}
	cout<<ans%mod<<endl;
	
}