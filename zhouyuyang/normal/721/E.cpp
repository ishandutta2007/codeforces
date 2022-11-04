#include<bits/stdc++.h> 
using namespace std;
int f[100005],h[100005];
int i,l,n,o,p,t,x,y;
inline void update(int l,int w,int x,int y){
	int v1=w+(y-x)/p,v2=x+(y-x)/p*p;
	if (v1>f[l]) f[l]=v1,h[l]=v2;
	else if (v1==f[l]) h[l]=min(h[l],v2);
}
int main(){
	scanf("%d%d%d%d",&l,&n,&p,&t);
	h[0]=-t;
	for (i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		o-=(o!=0);
		for (;o<i&& (h[o]+t<=y);o++)
			update(i,f[o],max(x,h[o]+t),y);
		if (f[i]<f[i-1])
			f[i]=f[i-1],h[i]=h[i-1];
		else if (f[i]==f[i-1])
			h[i]=min(h[i],h[i-1]);
	}
	printf("%d",f[n]);
}