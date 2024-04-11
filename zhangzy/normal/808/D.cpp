#include<bits/stdc++.h>
#define ll long long
#define ioi(x) exit(0*puts(x))
using namespace std;
int n,a[101000];
ll sum,now;
map<ll,bool>mp;

void doit(){
	mp.clear(); now=0;
	for (int i=1;i<=n;i++){
		now+=a[i]; mp[a[i]]=1;
		if (mp.count(now-sum)) ioi("YES");
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;sum+=a[i++]) scanf("%d",&a[i]);
	if (sum&1) ioi("NO"); sum>>=1;
	doit(); reverse(a+1,a+n+1); doit();
	ioi("NO");
}