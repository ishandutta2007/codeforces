#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int main(){
	int n,h;scanf("%d%d",&n,&h);
	for(int i=1;i<n;++i){
		printf("%.9lf ",sqrt((double)h*h*(double)i/(double)n));
	}
}