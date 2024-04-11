#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	int a1,a2,a3,b1,b2,b3,n;
	scanf("%d%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3,&n);

	a1+=a2; a1+=a3; a1+=4;
	b1+=b2; b1+=b3; b1+=9;

	if(a1/5+b1/10<=n)printf("YES\n");
	else printf("NO\n");
}