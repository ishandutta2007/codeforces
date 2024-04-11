#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,a[N],i,b[N],j,s,ans=N;
pair<int,int>c[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),c[i]=make_pair(a[i],i);
	sort(c+1,c+n+1);
	for(i=1;i<=n;++i)a[c[i].second]=j+=c[i].first>c[i-1].first;
	for(i=1;i<=n;++i){
		s=0;
		memset(b+1,0,n<<2);
		for(j=1;j<=n;++j)s+=2==++b[a[j]];
		for(j=i;j<=n;++j){
			if(!s)break;
			s-=1==--b[a[j]];
		}
		if(!s)ans=min(ans,j-i);
	}
	printf("%d\n",ans);
	return 0;
}