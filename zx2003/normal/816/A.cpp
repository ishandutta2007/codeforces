#include<cstdio> 
#include<cctype>
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int a,b,x,i;
char c[10];
int main(){
	scanf("%s",c+1);
	a=(c[1]-48)*10+c[2]-48;
	b=(c[4]-48)*10+c[5]-48;
	if(a==23 && b>32)return printf("%d\n",60-b),0;
	for(i=a;i<24;++i){
		x=i%10*10+i/10;
		if(x<60 &&(i>a || x>=b))break;
	}
	if(i>a)printf("%d\n",60-b+(i-a-1)*60+x);
		else printf("%d\n",x-b);
	return 0;
}