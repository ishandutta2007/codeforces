#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    write(a); puts("");
}
const int N=200005;
int ans,n,first,r,x;
struct data{
	int val,pos;
}a[N];
inline bool cmp(data a,data b){
	return a.val<b.val;
}
int main(){
	srand(time(0));
    n=read(); first=read(); x=read();
    for(int i=1;i<=990;i++){
    	int tt=rand()%2,zs;
    	if(n==1)zs=1; else
    	if(tt){
    		zs=rand()%(n/2)+1;
		}else{
			zs=rand()%(n/2)+n/2+1;
		}
    	printf("? %d\n",zs);
    	fflush(stdout);
    	int t1=read(),t2=read();
    	a[++r]=(data){t1,zs}; 
	}
	sort(&a[1],&a[r+1],cmp);
	int j=first;
	for(int i=r;i;i--){
		if(a[i].val<=x){j=a[i].pos; break;}
	}
	while(1){
		printf("? %d\n",j);
		fflush(stdout);
		int t1=read(),t2=read();
		if(t1>=x){
			printf("! %d\n",t1);
			fflush(stdout); return 0;
		}
		if(t2==-1){
			puts("! -1"); fflush(stdout); return 0;
		}
		j=t2;
	}
}