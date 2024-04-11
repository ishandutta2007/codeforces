#include<bits/stdc++.h>
using namespace std;
const int N=105;
int T,n,a[N],l[N],i,j;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		vector<int>ve;
		for(i=1;i<=n;++i){
			scanf("%d",l+i);
			if(l[i]==0)ve.push_back(a[i]);
		}
		sort(ve.begin(),ve.end(),greater<int>());j=0;
		for(i=1;i<=n;++i)if(l[i]==0)a[i]=ve[j++];
		for(i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');
	}
}