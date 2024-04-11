/*#include<bits/stdc++.h> 
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if (n>30) printf("%d\n",m);
	else printf("%d\n",m&((1<<n)-1));
}*/
#include<bits/stdc++.h>
using namespace std;
int n,fa[1005],deg[1005],son[1005];
int main(){
	scanf("%d",&n);
	deg[1]++;
	for (int i=2;i<=n;i++)
		scanf("%d",&fa[i]),deg[i]++,deg[fa[i]]++;
	for (int i=2;i<=n;i++)
		if (deg[i]==1) son[fa[i]]++;
	for (int i=1;i<=n;i++)
		if (deg[i]!=1&&son[i]<3)
			return puts("No"),0;
	puts("Yes");
}