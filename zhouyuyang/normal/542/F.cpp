#include<bits/stdc++.h>
using namespace std;
vector<int> vec[105];
int n,T,x,y;
int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x,&y),vec[x].push_back(y);
	for (int i=1;i<T;i++){
		sort(vec[i].begin(),vec[i].end());
		for (int j=vec[i].size()-1;j>=0;j-=2)
			if (j-1>=0)
				vec[i+1].push_back(vec[i][j]+vec[i][j-1]);
			else vec[i+1].push_back(vec[i][j]);
	}
	sort(vec[T].begin(),vec[T].end());
	printf("%d",vec[T][vec[T].size()-1]);
}