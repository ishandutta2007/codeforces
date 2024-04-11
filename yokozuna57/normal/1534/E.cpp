#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int main(){
	int n,k;
	cin>>n>>k;
	
	if(k%2==0&&n%2==1){
		cout<<-1<<endl;
		fflush(stdout);
		return 0;
	}
	
	int cnt[502]={};
	for(int i=1;i<=n;i++)cnt[i]=1;
	int sum=n;
	int max_c=1;
	while(sum%k!=0||sum<max_c*k){
		for(int i=1;i<=n;i++){
			if(sum%k!=0||(n%k!=0&&sum<max_c*k)){
				cnt[i]+=2;
				max_c=max(max_c,cnt[i]);
				sum+=2;
			}
		}
	}
	
	int ret=0;
	while(sum>0){
		vector<pair<int,int>> v;
		for(int i=1;i<=n;i++)v.push_back(mp(cnt[i],i));
		sort(v.begin(),v.end(),greater<pair<int,int>>());
		cout<<"?";
		for(int i=0;i<k;i++){
			cout<<" "<<v[i].sc;
			cnt[v[i].sc]--;
		}
		sum-=k;
		cout<<endl;
		fflush(stdout);
		int r;
		cin>>r;
		ret^=r;
	}
	cout<<"! "<<ret<<endl;
	fflush(stdout);
}