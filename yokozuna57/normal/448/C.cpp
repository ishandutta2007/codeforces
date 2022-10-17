#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dfs(vector<int> fen){
	int ret=1;

	vector<int> new_fen;

	for(int i=0;i<fen.size();i++){
		if(fen[i]!=1)new_fen.push_back(fen[i]-1);
		else {
			ret+=dfs(new_fen);
			new_fen.clear();
		}
	}
	if(new_fen.size()!=0)ret+=dfs(new_fen);

	return min(ret,(int)fen.size());
}

int main(){
	int n;
	int a[5010];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int ret=0;
	vector<int> fen;

	for(int i=0;i<n;i++){
		if(a[i]>=n)ret++;
		else {
			fen.push_back(a[i]);
		}
	}

	ret+=dfs(fen);

	printf("%d\n",ret);
}