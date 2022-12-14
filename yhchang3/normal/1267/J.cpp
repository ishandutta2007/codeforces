#include<bits/stdc++.h>
using namespace std;


int cnt[2000010];


inline bool check(int x,int s){
	if(x%s==0||x%(s-1)==0)	return true;
	return x/s+1<=x/(s-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cnt[i]=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			cnt[x]++;
		}
		vector<int> v;
		for(int i=1;i<=n;i++)
			if(cnt[i]!=0)
				v.emplace_back(cnt[i]);
		int m=1e8;
		for(int it:v)
			m=min(m,it);
		m++;
		while(true){
			bool ok=true;
			for(int it:v){
				if(!check(it,m)){
					ok=false;
					break;
				}
			}
			if(ok)
				break;
			else
				m--;
		}
		int ans=0;
		for(int it:v){
			if(it%m==0)
				ans+=it/m;
			else
				ans+=it/m+1;
		}
		cout<<ans<<'\n';
	}
}