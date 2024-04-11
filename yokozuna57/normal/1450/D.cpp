#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

int n;
int a[300010];

int ret[300010];
bool used[300010];

void solve(){
	//k=1
	for(int i=0;i<n;i++)used[i]=false;
	for(int i=0;i<n;i++)used[a[i]]=true;
	ret[1]=1;
	for(int i=0;i<n;i++){
		if(!used[i])ret[1]=0;
	}
	//k=n
	if(used[0])ret[n]=1;
	else ret[n]=0;
	//2<=n<=k-1
	int t=0;
	int l=0,r=n-1;
	while(1){
		if(a[l]!=t&&a[r]!=t)break;
		if(a[l]==t)l++;
		else r--;
		t++;
	}
	for(int i=l;i<=r;i++){
		t=min(t,a[i]+1);
	}
	for(int i=2;i<n;i++){
		if(i<n-t)ret[i]=0;
		else if(i==n-t){
			int cnt=0;
			for(int j=0;j<n;j++)if(a[j]==t-1)cnt++;
			if(cnt==1&&used[t])ret[i]=1;
			else ret[i]=0;
		}
		else ret[i]=1;
	}
	for(int i=1;i<=n;i++){
		printf("%d",ret[i]);
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]); a[i]--;
		}
		solve();
	}
}