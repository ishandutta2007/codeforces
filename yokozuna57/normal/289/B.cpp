#include<iostream>
using namespace std;

int main(){
	bool c=true,e=false;
	int n,m,d,a[100+2][100+2],b[10000+2],s=0,ans=0,dd,ee;
	fill(b,b+10002,0);
	scanf("%d%d%d",&n,&m,&d);
	dd=n*m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			b[a[i][j]]++;
		}
	}
	for(int i=1;i<=10000;i++){
		ee=b[i];
		if(b[i]!=0){
			if(s==0)s=i;
			if((i-s)%d!=0){c=false; break;}
			ans+=(i-s)/d*b[i];
		}
		b[i]+=b[i-1];
		if(2*b[i]>=dd&&!e&&ee!=0){e=true; ans=b[i]*((i-s)/d)-ans; s=i;}
	}
	if(c)printf("%d\n",ans);
	else printf("-1");
}