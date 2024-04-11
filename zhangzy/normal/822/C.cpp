#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define inf 2052023333
#define xxx 520233
using namespace std;
int n,k,ans;
struct P{
	int l,r,v;
}p[xxx];
vector<P>v1[xxx],v2[xxx];

bool left_right(P p1,P p2){
	return p1.l<p2.l;
}
bool cheaper(P p1,P p2){
	return p1.v<p2.v;
}

void doit(int x,int y){
	sort(v1[x].begin(),v1[x].end(),left_right);
	sort(v2[y].begin(),v2[y].end(),cheaper);
	int sz1=v1[x].size(),sz2=v2[y].size(),p1=0,p2=0;
	while (p1<sz1&&p2<sz2){
		while (v2[y][p2].l<=v1[x][p1].r&&p2<sz2) p2++;
		if (p2<sz2){
			ans=min(ans,v1[x][p1].v+v2[y][p2].v);
		}
		p1++;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].v);
		v1[p[i].r-p[i].l+1].push_back(p[i]);
		v2[p[i].r-p[i].l+1].push_back(p[i]);
	}
	
	ans=inf;
	for (int i=1;i<k;i++){
		doit(i,k-i);
	}
	
	printf("%d",ans==inf?-1:ans);
}