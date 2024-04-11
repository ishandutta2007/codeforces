#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	int n,m,ret=0;
	int v[1010],a,b;

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		ret+=min(v[a],v[b]);
	}

	printf("%d\n",ret);
}