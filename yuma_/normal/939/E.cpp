#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;

int main() { 
	int Q;cin>>Q;
	map<int,int>mp;
	while(Q--){
		int k;scanf("%d",&k);
		if(k==1){
			int a;scanf("%d",&a);
			mp[a]++;
		}else{
			int max_num=prev(mp.end())->first;

			ld sum=max_num;
			int cnt=1;

			for(auto it=mp.begin();it!=mp.end();++it){
				ld ave=sum/cnt;
				if(ave>it->first){
					sum+=it->first*it->second;
					cnt+=it->second;
				}else{
					break;
				}
			}
			double ans=max_num-sum/cnt;
			printf("%.9lf\n",ans);
		}
	}
	return 0;

}