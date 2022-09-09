#include<cstdio>
#include<cstdlib>
#include<algorithm>
int h,m,s,t1,t2;
double a[5],x,y;
inline void out(){
	puts("YES"),exit(0);
}
int main(){
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);h%=12,t1=t1%12,t2=t2%12;x=t1/12.0,y=t2/12.0;
	a[1]=(h*3600+m*60+s)/43200.0,a[2]=(m*6.0+s*0.1)/360,a[3]=s/60.0;
	std::sort(a+1,a+4);
	if((x<a[1] || a[3]<x) && (y<a[1] || a[3]<y))out();
	if(a[1]<x && x<a[2] && a[1]<y && y<a[2])out();
	if(a[2]<x && x<a[3] && a[2]<y && y<a[3])out();
	puts("NO");
	return 0;
}