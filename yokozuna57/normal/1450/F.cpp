#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

int n;
int a[100010];

int cnt[100010];
int solve(){
	for(int i=0;i<n;i++)cnt[i]=0;
	int k=1;
	cnt[a[0]]++;
	cnt[a[n-1]]++;
	for(int i=0;i+1<n;i++){
		if(a[i]==a[i+1]){
			cnt[a[i]]+=2;
			k++;
		}
	}
	pair<int,int> M=mp(0,0);
	for(int i=0;i<n;i++)M=max(M,mp(cnt[i],i));
	int t=0;
	for(int i=0;i+1<n;i++){
		if(a[i]!=a[i+1]&&a[i]!=M.sc&&a[i+1]!=M.sc)t++;
	}
	while(M.fr>=k+2){
		if(t==0)return -1;
		t--;
		k++;
	}
	return k-1;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		printf("%d\n",solve());
	}
}