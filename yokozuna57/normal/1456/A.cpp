#include <bits/stdc++.h>
using namespace std;

int n,p,k;
string s;
int x,y;

int cnt[100010];
int solve(){
	int ret=1000000000;
	for(int i=n-1;i>=p;i--){
		if(i+k<n)cnt[i]=cnt[i+k];
		else cnt[i]=0;
		if(s[i]=='0')cnt[i]++;
		ret=min(ret,cnt[i]*x+y*(i-p));
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d%d",&n,&p,&k); p--;
		cin>>s;
		scanf("%d%d",&x,&y);
		printf("%d\n",solve());
	}
}