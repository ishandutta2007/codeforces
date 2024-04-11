#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm> 
#define M 5005
using namespace std;
int n,v[100005],x,s,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++){
		scanf("%d",&x);
		if (!v[x]){
			v[x]=1;
			s++;
			if (s>ans) ans=s;
		}
		else{
			v[x]=0;
			s--;
		}
	}
	printf("%d",ans);
}