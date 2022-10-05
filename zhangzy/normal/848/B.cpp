#include<bits/stdc++.h>
#define xxx 200000
using namespace std;
int n,w,h,sz,anx[222222],any[222222];
struct P{
	int dir,x,y,id;
};
vector<P>vec[444444],en;

bool CX(P p1,P p2){
	return p1.x<p2.x;
}
bool CC(P p1,P p2){
	return p1.x-p1.y<p2.x-p2.y;
}

int main(){
	scanf("%d%d%d",&n,&w,&h);
	int d,t,x,y,z;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&d,&z,&t);
		if (d==1){
			x=z;y=-t;
		}else{
			x=-t;y=z;
		}
		vec[x+y+xxx].push_back((P){d,x,y,i});
	}
	for (int i=0;i<=422222;i++){
		if ((sz=(int)vec[i].size())==0) continue;
		sort(vec[i].begin(),vec[i].end(),CX);
		en.clear();
		for (int j=0;j<sz;j++){
			if (vec[i][j].dir==1){
				en.push_back((P){0,vec[i][j].x,h,0});
			}else{
				en.push_back((P){0,w,vec[i][j].y,0});
			}
		}
		sort(en.begin(),en.end(),CC);
		for (int j=0;j<sz;j++){
			anx[vec[i][j].id]=en[j].x;
			any[vec[i][j].id]=en[j].y;
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d %d\n",anx[i],any[i]);
	}
}