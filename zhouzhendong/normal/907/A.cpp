#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int v1,v2,v3,v4;
bool check(int v,int x){
	return v<=x&&x<=2*v;
}
int main(){
	scanf("%d%d%d%d",&v1,&v2,&v3,&v4);
	int flag=0;
	for (int x3=v4;x3<=v4*2;x3++){
		if (!check(v3,x3))
			continue;
		int x2=max(v4*2+1,v2);
		if (x2>v2*2)
			continue;
		int x1=max(x2+1,v1);
		if (x1>v1*2)
			continue;
		printf("%d\n%d\n%d",x1,x2,x3);
		flag=1;
		break;
	}
	if (!flag)
		puts("-1");
	return 0;
}