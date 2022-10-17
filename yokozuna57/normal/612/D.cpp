#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,k;
int l[1000010],r[1000010];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d",&l[i],&r[i]);
	
	vector<pair<int,int>> vec;
	for(int i=0;i<n;i++){
		vec.push_back(mp(l[i],-1));
		vec.push_back(mp(r[i],1));
	}
	sort(vec.begin(),vec.end());
	
	vector<int> ret;
	int cnt=0;
	for(auto p: vec){
		cnt+=p.sc;
		if(p.sc==-1&&cnt==-k)ret.push_back(p.fr);
		if(p.sc==1&&cnt==-(k-1))ret.push_back(p.fr);
	}
	cout<<ret.size()/2<<endl;
	for(int i=0;i+1<ret.size();i+=2){
		printf("%d %d\n",ret[i],ret[i+1]);
	}
}