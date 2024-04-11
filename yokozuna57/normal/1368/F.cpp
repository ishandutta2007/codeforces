#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	int n;
	cin>>n;
	
	int R=0;
	int K=2;
	for(int k=2;k<=n;k++){
		int l=n;
		int m=0;
		while(l>k){
			l-=k;
			m++;
		}
		if(R<n-m-k){
			R=n-m-k;
			K=k;
		}
	}
	
	bool ok[1002];
	for(int i=1;i<=n;i++){
		ok[i]=(i%K)!=1;
	}
	bool on[1002];
	for(int i=1;i<=n;i++){
		on[i]=false;
	}
	
	int cnt=0;
	while(cnt<R){
		vector<int> ret;
		for(int i=1;i<=n;i++){
			if(ok[i]&&!on[i]){
				ret.push_back(i);
				on[i]=true;
				cnt++;
			}
		}
		cout<<ret.size();
		for(int i=0;i<ret.size();i++){
			cout<<" "<<ret[i];
		}
		cout<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		for(int i=0;i<ret.size();i++){
			if(on[x]){
				on[x]=false;
				cnt--;
			}
			x++;
			if(x>n)x=1;
		}
	}
	cout<<0<<endl;
	fflush(stdout);
}