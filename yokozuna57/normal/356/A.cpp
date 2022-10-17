#include<iostream>
using namespace std;

int main(){
	static int n,m,ans[300000+2]={0},nex[300000+2]={0},x,l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)nex[i]=i+1;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&l,&r,&x);
		for(int j=l;j<=r;){
			if(j!=x&&ans[j]==0)ans[j]=x;
			j=nex[j];
		}
		for(int j=l;j<=r;){
			int ne=nex[j];
			if(j<x)nex[j]=x;
			else nex[j]=r+1;
			j=ne;
		}
		nex[l-1]=x;
	}
	for(int i=1;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n]);
}