#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
char x[300002],y[300002],s[300002];
int ry,ly,n,i,lx,rx,l,r,first; 
int main(){
	scanf("%s%s",x+1,y+1);
	n=strlen(x+1);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	first=(n>>1)+(n&1);
	lx=1;
	ly=first+1;
	rx=first;
	ry=n;
	l=1;
	r=n;
	for(i=1;i<=n;i++){
		if (i&1){
			if (x[lx]>=y[ry])s[r--]=x[rx--];
			else s[l++]=x[lx++];
		}else{
			if (y[ry]<=x[lx])s[r--]=y[ly++];
			else s[l++]=y[ry--];
		}
	}
	printf("%s",s+1);
}