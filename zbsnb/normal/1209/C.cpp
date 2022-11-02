#include<bits/stdc++.h>
using namespace std;
const int N=2e5+8;
int ans[N],a[N],b[N],c[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		string s;
		int n; scanf("%d",&n);
		cin>>s;
		for(int i=0;i<n;++i) a[i]=s[i]-'0',b[i]=a[i];
		sort(b,b+n);
		int now=0;
		for(int i=0;i<n;++i){
			if(a[i]==b[now]){
				++now;
				ans[i]=1;
			}
			else ans[i]=2;
		}
		now=-1;
		for(int i=0;i<n;++i){
			if(ans[i]==1) c[++now]=a[i];
		}
		for(int i=0;i<n;++i){
			if(ans[i]==2) c[++now]=a[i];
		}
		bool ok=1;
		for(int i=0;i<n;++i){
			if(b[i]!=c[i]){
				ok=0;
				break;
			}
		}
		if(ok){
			for(int i=0;i<n;++i) printf("%d",ans[i]);
			printf("\n");
		}
		else{
			puts("-");
		}
	}
	return 0;
}