#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l,r,s,x,p;
int main(){
	scanf("%d",&n);
	l=-1000000000;
	r=-l;
	p=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&s,&x);
		if (x==1) l=max(l,1900-p);
		if (x==2) r=min(r,1899-p);
		p+=s;
	}
	if (l>r) printf("Impossible");
		else if (r>999999999) printf("Infinity");
			else printf("%d",r+p);
	return 0;
}