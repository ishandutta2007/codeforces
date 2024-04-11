#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int main(){
	int n;
	cin>>n;
	
	vector<pair<int,int>> g[2];
	int k[2]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[(i+j)%2].push_back(mp(i,j));
		}
	}
	for(int i=0;i<n*n;i++){
		int a;
		scanf("%d",&a);
		int c;
		pair<int,int> ret;
		if(a==1){
			if(k[1]<g[1].size()){
				c=2;
				ret=g[1][k[1]];
				k[1]++;
			}
			else {
				c=3;
				ret=g[0][k[0]];
				k[0]++;
			}
		}
		else if(a==2){
			if(k[0]<g[0].size()){
				c=1;
				ret=g[0][k[0]];
				k[0]++;
			}
			else {
				c=3;
				ret=g[1][k[1]];
				k[1]++;
			}
		}
		else {
			if(k[0]<g[0].size()){
				c=1;
				ret=g[0][k[0]];
				k[0]++;
			}
			else {
				c=2;
				ret=g[1][k[1]];
				k[1]++;
			}
		}
		cout<<c<<" "<<ret.fr<<" "<<ret.sc<<endl;
		fflush(stdout);
	}
	return 0;
}