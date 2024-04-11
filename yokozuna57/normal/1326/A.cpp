#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		scanf("%d",&n);
		if(n==1){
			puts("-1");
			continue;
		}
		string s="";
		for(int i=0;i<n-1;i++)s+="3";
		s+="4";
		cout<<s<<endl;
	}
}