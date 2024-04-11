#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
char s[100];
inline bool ask(int x,int y){
	printf("1 %d %d\n",x,y);
	scanf("%s",s);
	return s[0]=='T';
}
inline int solve(int l,int r){
	while (l<r){
		int mid=(l+r)>>1;
		ask(mid,mid+1)?r=mid:l=mid+1;
	}
	return l;
}
int LE(int x){
	if (x==1) return 0;
	int t=solve(1,x-1);
	if (ask(t,x)){
		return t;
	}else{
		return 0;
	}
}
int RI(int x){
	int t=solve(x+1,n);
	return t;
}
main(){
	setvbuf(stdout,0,_IONBF,0);
	scanf("%d%d",&n,&k);
	int fi=solve(1,n);
	int t1=LE(fi);
	if (t1){
		printf("2 %d %d\n",fi,t1);
		return 0;
	}
	int t2=RI(fi);
	printf("2 %d %d\n",fi,t2);
	return 0;
}