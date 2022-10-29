#include<bits/stdc++.h>
using namespace std;
int n,m,q,cl,ce,v;
set<int>E,S;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=1,x;i<=cl;++i)scanf("%d",&x),S.insert(x);
	for(int i=1,x;i<=ce;++i)scanf("%d",&x),E.insert(x);
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			printf("%d\n",abs(y1-y2));
			continue;
		} else {
			int ans=1<<30,dt=abs(x1-x2);
			auto it=S.lower_bound(y1);
			if(it!=S.end())ans=min(ans,abs(*it-y1)+abs(*it-y2)+dt);
			if(it!=S.begin())it--,ans=min(ans,abs(*it-y1)+abs(*it-y2)+dt);
			it=E.lower_bound(y1);
			dt=(dt+v-1)/v;
			if(it!=E.end())ans=min(ans,abs(*it-y1)+abs(*it-y2)+dt);
			if(it!=E.begin())it--,ans=min(ans,abs(*it-y1)+abs(*it-y2)+dt);
			printf("%d\n",ans);
		}
	}
}