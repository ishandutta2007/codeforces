#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

vector<long long> yaku(long long n){
	vector<long long> ret;
	for(long long i=1;i*i<=n;i++){
		if(n%i==0){
			ret.push_back(i);
			if(i*i<n)ret.push_back(n/i);
		}
	}
	sort(ret.begin(),ret.end());
	return ret;
}

int main(){
	long long x,k;
	scanf("%I64d%I64d",&x,&k);

	map<long long,vector<long long>> m;
	stack<pair<long long,long long>> que;
	
	que.push(pair<long long,long long>(x,k));

	vector<long long> ans;
	for(long long i=0;i<100000;i++){

		while(!que.empty()){
			pair<long long,long long> p=que.top(); que.pop();
			
			if(p.first==1){
				ans.push_back(1);
				break;
			}

			if(p.second==0){
				ans.push_back(p.first);
				break;
			}
			
			map<long long,vector<long long>>::iterator itr=m.find(p.first);
			if(itr==m.end()){ m[p.first]=yaku(p.first); itr=m.find(p.first); }
			
			for(long long i=(*itr).second.size()-1;i>=0;i--){
				que.push(pair<long long,long long>((*itr).second[i],p.second-1));
			}
		}
	}

	for(long long i=0;i<ans.size();i++){
		if(i!=ans.size()-1)printf("%I64d ",ans[i]);
		else printf("%I64d\n",ans[i]);
	}
}