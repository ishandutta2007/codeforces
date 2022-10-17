#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,v;
	scanf("%d%d",&n,&v);

	vector<int> ans;

	for(int i=0;i<n;i++){
		bool c=false;
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int s;
			scanf("%d",&s);
			if(s<v)c=true;
		}

		if(c)ans.push_back(i+1);
	}

	printf("%d\n",ans.size());
	for(int i=0;i+1<ans.size();i++){
		printf("%d ",ans[i]);
	}
	if(ans.size()>0)printf("%d\n",ans[ans.size()-1]);
}