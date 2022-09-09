#include<bits/stdc++.h> 
using namespace std;
const int N=100005;
inline void upi(int&a,const int&b){a>b?a=b:0;}
int cl,ce,n,m,l[N],e[N],v;
int calcl(int x1,int y1,int x2,int y2){
	if(y1<1 || y1>m)return 1<<30;
	int j,ans=1<<30;
	j=lower_bound(l+1,l+cl+1,y1)-l;
	if(j<=cl)upi(ans,abs(y1-l[j])+abs(y2-l[j]));
	j=upper_bound(l+1,l+cl+1,y1)-l-1;
	if(j>=1)upi(ans,abs(y1-l[j])+abs(y2-l[j]));
	return ans+abs(x1-x2);
}
int calce(int x1,int y1,int x2,int y2){
	if(y1<1 || y1>m)return 1<<30;
	int j,ans=1<<30;
	j=lower_bound(e+1,e+ce+1,y1)-e;
	if(j<=ce)upi(ans,abs(y1-e[j])+abs(y2-e[j]));
	j=upper_bound(e+1,e+ce+1,y1)-e-1;
	if(j>=1)upi(ans,abs(y1-e[j])+abs(y2-e[j]));
	return ans+(abs(x1-x2)+v-1)/v;
}
int main(){
	int q,x1,y1,x2,y2,i;
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(i=1;i<=cl;++i)scanf("%d",l+i);
	sort(l+1,l+cl+1);
	for(i=1;i<=ce;++i)scanf("%d",e+i);
	sort(e+1,e+ce+1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			printf("%d\n",abs(y2-y1));
			continue;
		}
		int ans=min(calcl(x1,y1,x2,y2),calce(x1,y1,x2,y2));
		printf("%d\n",ans);
	}
	return 0;
}