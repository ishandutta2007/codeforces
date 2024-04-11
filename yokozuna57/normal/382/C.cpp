#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solver(vector<int> x,vector<int> y){
	int loc=0,ret=y[y.size()-1];
	for(int i=0;i<x.size();i++){
		while(x[i]!=y[loc]){ret=y[loc]; loc++; if(loc>=i+2)return -1000000000;}
		loc++;
	}
	return ret;
}

int main(){
	int n;
	int a;
	vector<int> seq;
	vector<int> ans;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		seq.push_back(a);
	}

	if(n==1)printf("-1\n");
	else {
		sort(seq.begin(),seq.end());
		int d=seq[1]-seq[0];
		vector<int> seq0,seq1,seq2;
		for(int i=0;i<n+1;i++){
			seq0.push_back(seq[0]+d*i);
			seq1.push_back(seq[0]+d*(i-1));
			seq2.push_back(seq[0]+(d/2)*i);
		}
		int sol;
		sol=solver(seq,seq0); if(sol!=-1000000000)ans.push_back(sol);
		sol=solver(seq,seq1); if(sol!=-1000000000)ans.push_back(sol);
		if(d%2==0)sol=solver(seq,seq2); if(sol!=-1000000000)ans.push_back(sol);

		sort(ans.begin(),ans.end());
		vector<int>::iterator itr=unique(ans.begin(),ans.end());
		ans.erase(itr,ans.end());

		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
		}
	}
}