#include<iostream>
using namespace std;

int main(){
	int p,n;
	int x[302];
	bool f[302];
	memset(f,false,sizeof(f));

	scanf("%d%d",&p,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}

	int ret=-1;
	for(int i=1;i<=n;i++){
		if(f[x[i]%p]){ ret=i; break; }
		else f[x[i]%p]=true;
	}

	printf("%d\n",ret);
}