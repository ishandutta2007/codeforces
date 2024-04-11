#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n,k;
int a[200010];
void solve(){
	sort(a,a+n);
	int nex=0,cnt=k,mex=-1;
	for(int i=0;i<n-k;i++){
		while(a[i]>nex){
			if(cnt==0){
				mex=nex;
				break;
			}
			else {
				cnt--;
				nex++;
			}
		}
		if(mex!=-1)break;
		if(a[i]==nex)nex++;
	}
	if(mex==-1){
		puts("0");
	}
	else {
		vector<int> v;
		int pre=-1;
		cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]!=pre){
				if(pre>mex)v.push_back(cnt);
				pre=a[i];
				cnt=1;
			}
			else cnt++;
		}
		v.push_back(cnt);
		sort(v.begin(),v.end());
		int sum=0;
		for(int i=0;i<v.size();i++){
			sum+=v[i];
			if(sum>k){
				printf("%d\n",(int)(v.size()-i));
				return;
			}
		}
		puts("0");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		solve();
	}
}