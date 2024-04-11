#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int seg[1<<18],seg2[1<<18],size;

void init(int x){
	size=1;
	while(size<x)size*=2;
	for(int i=0;i<size*2-1;i++)seg[i]=0;
}

void updata(int a,int b,int k,int l,int r){
	if(b<=l||r<=a)return;
	if(a<=l&&r<=b){seg[k]=1; return; }
	updata(a,b,2*k+1,l,(l+r)/2);
	updata(a,b,2*k+2,(l+r)/2,r);
	//seg[k]=max(seg[2*k+1],seg[2*k+2]);
}

void complete(){
	for(int i=0;i<=100000;i++){
		int x=i+size-1;
		int ret=seg[x];
		while(x>0){
			x=(x-1)/2;
			if(seg[x]==1)ret=1;
		}
		seg2[i+size-1]=ret;
	}
	for(int i=size-2;i>=0;i--){
		seg2[i]=max(seg2[2*i+1],seg2[2*i+2]);
	}
}

int MAX(int a,int b,int k,int l,int r){
	if(b<=l||r<=a)return 0;
	if(a<=l&&r<=b){return seg2[k];}
	int vl=MAX(a,b,2*k+1,l,(l+r)/2);
	int vr=MAX(a,b,2*k+2,(l+r)/2,r);
	return max(vl,vr);
}

int main(){
	int n,k;
	static vector<pair<int,int>> vp[100010];

	char c; int in,inin;

	scanf("%d%d",&n,&k); init(k+10);
	for(int i=0;i<k;i++){
		scanf("\n%c %d",&c,&in);
		if(c=='+')inin=1;
		else inin=0;
		vp[in].push_back(pair<int,int>(i+1,inin));
	}

	for(int i=1;i<=n;i++){
		vp[i].push_back(pair<int,int>(0,0));
		sort(vp[i].begin(),vp[i].end());
		int s=vp[i].size();
		for(int j=1;j<s;j++){
			if(vp[i][j].second==0){
				updata(vp[i][j-1].first,vp[i][j].first,0,0,size);
			}
		}
		if(s>1)if(vp[i][s-1].second==1){
			updata(vp[i][s-1].first,100010,0,0,size);
		}
	}

	complete();

	int ret=0;
	bool used[100010];
	for(int i=1;i<=n;i++){
		used[i]=true;
		int s=vp[i].size();
		for(int j=1;j<s;j++){
			if(vp[i][j].second==1){
				if(MAX(vp[i][j-1].first,vp[i][j].first,0,0,size)!=0)used[i]=false;
			}
		}
		if(s>1)if(vp[i][s-1].second==0){
			if(MAX(vp[i][s-1].first,100010,0,0,size)!=0)used[i]=false;
		}
		if(used[i])ret++;
	}
	printf("%d\n",ret);
	for(int i=1;i<=n;i++){
		if(used[i]){
			if(ret>1)printf("%d ",i);
			else printf("%d\n",i);
			ret--;
		}
	}
}