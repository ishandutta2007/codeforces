#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],k[N],now[N],ans,satis,del;
int main(){
	scanf("%d%d",&n,&m);
	ans=n+1;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	satis=del=0;
	for (int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		if (k[i]==0)
			satis++;
	}
	for (int i=1,j=1;i<=n;i++){
		while (satis<m&&j<=n){
			now[a[j]]++;
			if (now[a[j]]==k[a[j]])
				satis++;
			if (now[a[j]]>k[a[j]])
				del++;
			j++;
		}
		if (satis==m)
			ans=min(ans,del);
		if (now[a[i]]>k[a[i]])
			del--;
		if (now[a[i]]==k[a[i]])
			satis--;
		now[a[i]]--;
	}
	printf("%d",(ans==n+1)?-1:ans);
	return 0;
}