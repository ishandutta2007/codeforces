#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

bool f(pair<int,int> s,pair<int,int> t){
	if((s.first==t.first&&s.second<t.second)||s.first<t.first)return true;
	return false;
}

int main(){
	pair<int,int> point[8];
	for(int i=0;i<8;i++)scanf("%d%d",&point[i].first,&point[i].second);
	sort(point,point+8,f);
	if(point[0].first==point[1].first&&point[1].first==point[2].first&&point[2].first<point[3].first&&point[3].first==point[4].first&&point[4].first<point[5].first&&point[5].first==point[6].first&&point[6].first==point[7].first&&point[0].second==point[3].second&&point[3].second==point[5].second&&point[5].second<point[1].second&&point[1].second==point[6].second&&point[6].second<point[2].second&&point[2].second==point[4].second&&point[4].second==point[7].second)printf("respectable");
	else printf("ugly");
}




	/*int X[5],Y[5],k=0,l=0;
	int x[10],y[10];
	for(int i=0;i<8;i++){
		scanf("%d%d",&x[i],&y[i]);
		bool c=true;
		for(int j=0;j<k;j++){
			if(x[i]==X[j])c=false;
		}
		if(c){X[k]=x[i]; k++;}
		c=true;
		for(int j=0;j<l;j++){
			if(y[i]==Y[j])c=false;
		}
		if(c){Y[k]=y[i]; l++;}
	}*/