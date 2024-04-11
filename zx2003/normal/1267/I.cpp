#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
typedef pair<int,int>pii;
int T,n,i;pii a[199];V v;
int rk[19]={0,10,9,7,8,6,5,4,3,2,1};
bool cmp(int x,int y){
	printf("? %d %d\n",x,y);fflush(stdout);
	char c[4];scanf("%s",c);return *c=='<';
//	return rk[x]<rk[y];
}
bool cmpp(pii x,pii y){return cmp(x.first,y.first);}
void solve(V v,int k){
	assert(v.size()>k);
	if(k<5){
		int xb=0;
		for(;;){
			for(i=0;i+1<v.size();i+=2)a[++xb]=cmp(v[i],v[i+1])?pii(v[i],v[i+1]):pii(v[i+1],v[i]);
			sort(a+1,a+xb+1,cmpp);
			int t=v.size()&1?v.back():-1;
			v.clear();for(i=1;i+(k-3)<xb;++i)v.push_back(a[i].second);if(t!=-1)v.push_back(t);
			if(k==3)a[1]=a[xb],xb=1;else a[1]=a[xb-1],a[2]=a[xb],xb=2;
	//		if(xb*2+v.size()==k+1)break;
			if(xb*2+v.size()<=k || (k==4 && xb==2 && v.size()==1))break;
		}
		if(k==4 && xb==2 && v.size()==1)cmp(cmp(v[0],a[1].first)?v[0]:a[1].first,a[2].first);
/*
		if(k==3)assert(v.size()==2 && xb==1);
		if(k==4)assert(v.size()==1 && xb==2);
		if(k==3)cmp(cmp(v[0],v[1])?v[0]:v[1],a[1].first);
			else cmp(cmp(v[0],a[1].first)?v[0]:a[1].first,a[2].first);
*/
		return;
	}
	V low,high;
	for(i=1;i<v.size();++i)if(cmp(v[0],v[i]))high.push_back(v[i]);else low.push_back(v[i]);
	if(high.size()==k || high.size()+1==k)return;
	if(high.size()<k && high.size()>1){sort(low.begin(),low.end(),cmp);return;}
//	if(high.size()<=k && high.size()>1){sort(low.begin(),low.end(),cmp);return;}
	if(high.size()<k)solve(low,k-high.size()-1);
		else solve(high,k);
}
int main(){
	srand(time(0));
//	n=8;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
//		random_shuffle(rk+1,rk+n*2+1);
//		for(i=1;i<=n*2;++i)printf("%d ",rk[i]);puts("");
//		for(i=1;i<=n*2;++i)scanf("%d",rk+i);
		v.resize(n*2);for(i=0;i<n*2;++i)v[i]=i+1;
		solve(v,n);puts("!");fflush(stdout);
	}
	return 0;
}