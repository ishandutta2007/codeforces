#include<bits/stdc++.h>
using namespace std;

long long int m,x;

long long int mul(long long int a,long long int b,long long int mod){
	long long int res=0;
	while(b){
		res=(res+a*(b&((1<<16)-1)))%mod;
		b>>=16;
		a<<=16;
		a%=mod;
	}
	return res;
}

long long int pw(long long int a,long long int b,long long int mod){
	long long int res=1;
	while(b){
		if(b&1)
			res=mul(res,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return res;
}

vector<pair<long long int,int> > factorize(long long int p){
	vector<pair<long long int,int> > res;
	for(long long int i=2;i*i<=p;i++)
		if(p%i==0){
			int cnt=0;
			while(p%i==0){
				p/=i;
				cnt++;
			}
			res.emplace_back(make_pair(i,cnt));
		}
	if(p>1)
		res.emplace_back(make_pair(p,1));
	return res;
}

long long int lcm(long long int a,long long int b){
	return a/__gcd(a,b)*b;
}

long long int period(long long int p){
	vector<pair<long long int,int> > f=factorize(p-1);
	long long int now=p-1;
	for(auto it:f)
		while(now%it.first==0&&pw(x,now/it.first,p)==1)
			now/=it.first;
	return now;
}

long long int ans=0;
vector<vector<long long int> > P;
vector<pair<long long int,int> > facs;
void dfs(int idx,long long int phi,long long int periods){
	if(idx==P.size()){
		ans+=phi/periods;
		return;
	}
	for(int i=0;i<P[idx].size();i++){
		dfs(idx+1,phi,lcm(periods,P[idx][i]));
		if(i==0)	phi*=facs[idx].first-1;
		else	phi*=facs[idx].first;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>x;
	facs=factorize(m);
	P.resize(facs.size());
	for(int i=0;i<facs.size();i++){
		P[i].emplace_back(1);
		long long int now=facs[i].first;
		for(int j=1;j<=facs[i].second;j++){
			if(j==1)
				P[i].emplace_back(period(now));
			else{
				now*=facs[i].first;
				if(pw(x,P[i].back(),now)==1)	P[i].emplace_back(P[i].back());
				else
					P[i].emplace_back(P[i].back()*facs[i].first);
			}
		}
	}
	dfs(0,1,1);
	cout<<ans<<endl;
}