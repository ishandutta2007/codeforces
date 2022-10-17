#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	long long int n,k,x,y;
	static vector<long long int> cnt[300010],p;

	scanf("%I64d%I64d",&n,&k);
	for(long long int i=0;i<n;i++){
		scanf("%I64d%I64d",&x,&y);
		cnt[x].push_back(y);
		cnt[y].push_back(x);
	}
	for(long long int i=1;i<=n;i++){
		p.push_back(cnt[i].size());
		sort(cnt[i].begin(),cnt[i].end());
	}
	sort(p.begin(),p.end());
	
	long long int ret=0;
	for(long long int i=1;i<=n;i++){
		long long int kk=k-cnt[i].size();
		ret+=n-(lower_bound(p.begin(),p.end(),kk)-p.begin()); if(cnt[i].size()>=kk)ret--;
		for(long long int j=0;j<cnt[i].size();j++){
			if(j==0||cnt[i][j]!=cnt[i][j-1]){
				if(cnt[cnt[i][j]].size()>=kk&&cnt[cnt[i][j]].size()-(upper_bound(cnt[i].begin(),cnt[i].end(),cnt[i][j])-lower_bound(cnt[i].begin(),cnt[i].end(),cnt[i][j]))<kk){
					ret--;
				}
			}
		}
	}

	printf("%I64d\n",ret/2);
}