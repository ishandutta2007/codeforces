#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int a[200010];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]); a[i]--;
	}
	
	ll cnt[12]={};
	for(int i=0;i<n;i++)cnt[a[i]]++;
	
	ll ret=0;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			ret+=cnt[i]*cnt[j];
		}
	}
	cout<<ret<<endl;
}