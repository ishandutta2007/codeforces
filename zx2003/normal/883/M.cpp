#include<cstdio>
inline int abs(int x){return x>0?x:-x;}
int main(){
	static int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b==d)return printf("%d\n",6+abs(a-c)*2),0;
	if(a==c)return printf("%d\n",6+abs(b-d)*2),0;
	printf("%d\n",abs(a-c)*2+abs(b-d)*2+4);
	return 0;
}