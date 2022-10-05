#include<bits/stdc++.h>
#define pii pair<int,int>
#define mo1 1000000007
#define mo2 1000000009
#define p (pii){t1,t2}
using namespace std;

int n,m;
vector<int>r[1001000];
map<pii,int>mp;
long long ans=0;

int main(){
	scanf("%d%d",&n,&m);
	for (int x,y;m--;){
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	int t1,t2;
	for (int tim=2;tim--;){
		mp.clear();
		for (int i=1;i<=n;i++){
			t1=1;t2=1;
			if (!tim) r[i].push_back(i);
			sort(r[i].begin(),r[i].end());
			for (int j=0;j<(int)r[i].size();j++){
				t1=(t1*233ll+r[i][j])%mo1;
				t2=(t2*23ll+r[i][j])%mo2;
			}
			ans+=mp[p]++;
		}	
	}
	cout<<ans;
}