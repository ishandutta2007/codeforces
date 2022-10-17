#include<iostream>
#include<vector>
using namespace std;
pair<long long int,vector<long long int>> p[10][10];

vector<long long int> solve(long long int n){
	//cout<<n<<endl;
	//cin>>p[9][9].first;
	vector<long long int>ret;
	if(n==0){
		for(int i=0;i<6;i++)ret.push_back(0);
		return ret;
	}
	for(int i=0;i<=6;i++){
		for(int j=0;j<=6-i;j++){
			if(p[i][j].first%10==n%10&&p[i][j].first<=n){
				ret=solve((n-p[i][j].first)/10);
				if(ret[0]!=-1){
					//cout<<i<<j<<endl;
					for(int k=0;k<6;k++){
						ret[k]*=10;
						ret[k]+=p[i][j].second[k];
					}
					return ret;
				}
			}
		}
	}
	for(int i=0;i<6;i++)ret.push_back(-1);
	return ret;
}

int main(){
	long long int t,n;
	scanf("%I64d",&t);
	for(int i=0;i<=6;i++){
		for(int j=0;j<=6-i;j++){
			p[i][j].first=j*4+(6-i-j)*7;
			vector<long long int> ret;
			for(int k=0;k<i;k++)ret.push_back(0);
			for(int k=0;k<j;k++)ret.push_back(4);
			for(int k=0;k<6-i-j;k++)ret.push_back(7);
			p[i][j].second=ret;
		}
	}
	//cout<<p[5][0].second[5];
	for(int i=0;i<t;i++){
		scanf("%I64d",&n);
		vector<long long int> ans=solve(n);
		if(ans[0]==-1)printf("-1");
		else for(int j=0;j<6;j++){printf("%I64d",ans[j]); if(j!=5)printf(" ");}
		printf("\n");
	}
}