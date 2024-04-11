#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	int n;
	int a[200010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	int cnt[20]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<20;j++){
			if((a[i]>>j)&1)cnt[j]++;
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++){
		ll x=0;
		for(int j=0;j<20;j++){
			if(i<cnt[j])x+=1<<j;
		}
		ret+=x*x;
	}
	cout<<ret<<endl;
}