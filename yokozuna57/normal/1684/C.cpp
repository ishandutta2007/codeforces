#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n,m;
vector<vector<int>> a;
void solve(){
	vector<int> v;
	for(int i=0;i<m;i++)v.push_back(i);
	sort(v.begin(),v.end(),[](auto x,auto y){
		for(int j=0;j<n;j++){
			if(a[j][x]!=a[j][y])return a[j][x]<a[j][y];
		}
		return true;
	});
	bool ok=true;
	for(int i=0;i<n;i++)for(int j=0;j+1<m;j++){
		ok&=a[i][v[j]]<=a[i][v[j+1]];
	}
	if(!ok){
		puts("-1");
		return;
	}
	vector<int> b(m);
	int k=0;
	for(int j=0;j<m;j++){
		if(j>0){
			for(int i=0;i<n;i++){
				if(a[i][v[j]]!=a[i][v[j-1]]){
					k++;
					break;
				}
			}
		}
		b[v[j]]=k;
	}
	vector<int> c=b;
	sort(c.begin(),c.end());
	
	vector<int> ret;
	for(int i=0;i<m;i++)if(b[i]!=c[i])ret.push_back(i);
	if(ret.size()==0){
		puts("1 1");
	}
	else if(ret.size()==2){
		printf("%d %d\n",ret[0]+1,ret[1]+1);
	}
	else {
		puts("-1");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		a=vector<vector<int>>(n,vector<int>(m));
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
		solve();
	}
}