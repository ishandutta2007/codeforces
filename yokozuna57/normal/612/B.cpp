#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[200010];
ll b[200010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	
	for(int i=0;i<n;i++){
		b[a[i]]=i;
	}
	ll ret=0;
	for(int i=0;i+1<n;i++){
		ret+=abs(b[i]-b[i+1]);
	}
	cout<<ret<<endl;
}