#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int T,n,i,j,x,y,c0,c1,c2;
char a[N],b[N],oob[N];
int ans[N],acnt;
void rev(int l){ans[++acnt]=l;reverse(a+1,a+l+1);}
int ps;
bool ck(){
	c0=c1=c2=0;
	for(i=2;i<=n;i+=2){
		(a[i]==a[i-1]?(a[i]=='1'?c1:c0):c2)++;
		(b[i]==b[i-1]?(b[i]=='1'?c1:c0):c2)--;
	}
	return !c0 && !c1 && !c2;
}
void pre_rev(){
	int ca=0,cb=0,cc=0;
	for(i=2;i<=n;i+=2){
		ca+=a[i-1]!=a[i]?a[i-1]=='0'?1:-1:0;
		cb+=b[i-1]!=b[i]?b[i-1]=='1'?1:-1:0;
	}
	if(abs(ca)>abs(cb)){
		for(i=2;ca-cc*2!=cb;i+=2)cc+=a[i-1]!=a[i]?a[i-1]=='0'?1:-1:0;
		ps=-1;if(i>2)rev(i-2);
	}else{
		for(i=n-1;cb-cc*2!=ca;i-=2)cc+=b[i+1]!=b[i]?b[i]=='1'?1:-1:0;
		ps=n-i-1;reverse(b+i+2,b+n+1);
	}
}
int main(){
	for(scanf("%d",&T);T--;){
		acnt=0;
		scanf("%s%s",a+1,b+1);n=strlen(a+1);
memcpy(oob+1,b+1,n+1);
		if(!ck()){puts("-1");continue;}
		pre_rev();
		for(i=2;i<=n;i+=2){
			for(j=i;a[j]!=b[n-i+1] || a[j-1]!=b[n-i+2];j+=2);
			if(j>2)rev(j-2);rev(j);
			if(i==ps)rev(i);
		}
assert(strcmp(a+1,oob+1)==0);
		printf("%d\n",acnt);for(i=1;i<=acnt;++i)printf("%d%c",ans[i],i==acnt?'\n':' ');
	}
	return 0;
}