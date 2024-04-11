#include<cstdio>
inline int idx(char c){
	if(c=='v')return 0;
	if(c=='<')return 1;
	if(c=='^')return 2;
	if(c=='>')return 3;
	return 0;
}
char c2[3],c1[3];
int n,a,b;
int main(){
	scanf("%s%s%d",c1,c2,&n);
	a=idx(*c1);
	b=idx(*c2);
	n%=4;
	if(!n || ((a+n)%4==b && n==2))puts("undefined");
		else if((a+n)%4==b)puts("cw");
				else if((b+n)%4==a)puts("ccw");
	return 0;
}