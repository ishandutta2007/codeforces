#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	int n;
	cin>>n;
	
	vector<P> ret;
	for(int i=0;i<=2;i++)for(int j=0;j<=2;j++){
		if(i==1&&j==1)continue;
		ret.push_back(P(i,j));
	}
	for(int x=1;x<=n;x++){
		if(x&1){
			for(int i=2*x;i<=2*x+2;i++)for(int j=2;j<=4;j++){
				if(i==2*x&&j==2)continue;
				if(i==2*x+1&&j==3)continue;
				ret.push_back(P(i,j));
			}
		}
		else {
			for(int i=2*x;i<=2*x+2;i++)for(int j=0;j<=2;j++){
				if(i==2*x&&j==2)continue;
				if(i==2*x+1&&j==1)continue;
				ret.push_back(P(i,j));
			}
		}
	}
	printf("%d\n",(int)ret.size());
	for(int i=0;i<ret.size();i++){
		printf("%d %d\n",ret[i].fr,ret[i].sc);
	}
}