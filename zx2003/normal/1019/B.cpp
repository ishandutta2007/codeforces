#include<bits/stdc++.h>
int n,l,r,m,x,y,a,b;
int ask(int i){
	printf("? %d\n",i);fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
void exi(int z){
	printf("! %d\n",z);fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d",&n);
	if((n/2)&1)exi(-1);
	a=ask(1);b=ask(1+n/2);
	if((a-b)&1)exi(-1);
	if(a==b)exi(1);
	for(l=2,r=n/2;l<r;){
		m=(l+r)>>1;
		x=ask(m);y=ask(m+n/2);
		if(x==y)exi(m);
		if(1ll*(a-b)*(x-y)>0)l=m+1;else r=m-1;
	}
	exi(l);
	return 0;
}