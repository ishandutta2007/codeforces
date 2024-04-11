#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	static vector<int> v[100010];
	static bool used[100010];
	vector<pair<int,int>> ans;

	for(int i=0;i<100010;i++)used[i]=false;

	for(int i=3;i<=n;i+=2){
		bool c=false;
		for(int j=3;j*j<=i;j++){
			if(i%j==0){
				v[j].push_back(i);
				c=true;
				break;
			}
		}
		if(!c)v[i].push_back(i);
	}

	for(int i=3;i<=n;i+=2){
		for(int j=0;j+1<v[i].size();j+=2){
			ans.push_back(pair<int,int>(v[i][j],v[i][j+1]));
		}
		if(v[i].size()%2==1&&2*i<=n){
			ans.push_back(pair<int,int>(v[i][v[i].size()-1],2*i));
			used[2*i]=true;
		}
	}

	for(int i=2;i<=n;i+=2){
		if(!used[i]){
			v[2].push_back(i);
		}
	}

	for(int i=0;i+1<v[2].size();i+=2){
		ans.push_back(pair<int,int>(v[2][i],v[2][i+1]));
	}

	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}