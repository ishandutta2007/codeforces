#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,cg[10];
int main(){
	scanf("%d",&n);
	for (int i=0;i<10;i++)
		cg[i]=2;
	while (n--){
		char opt[3];
		int v;
		scanf("%s%d",opt,&v);
		for (int i=0;i<10;i++){
			int x=(v>>i)&1;
			if (opt[0]=='|'&&x)
				cg[i]=1;
			if (opt[0]=='&'&&!x)
				cg[i]=0;
			if (opt[0]=='^'&&x)
				if (cg[i]==2)
					cg[i]=3;
				else if (cg[i]==3)
					cg[i]=2;
				else
					cg[i]=cg[i]^1;
		}
	}
	printf("3\n");
	int v=1023;
	for (int i=0;i<10;i++)
		if (cg[i]==0)
			v^=1<<i;
	printf("& %d\n",v);
	v=0;
	for (int i=0;i<10;i++)
		if (cg[i]==1)
			v|=1<<i;
	printf("| %d\n",v);
	v=0;
	for (int i=0;i<10;i++)
		if (cg[i]==3)
			v|=1<<i;
	printf("^ %d\n",v);
	return 0;
}