#include<bits/stdc++.h>
using namespace std;
int n;
long long sx=0,sy=0;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		sx+=x,sy+=y;
	}
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		sx+=x,sy+=y;
	}
	printf("%lld %lld\n",sx/n,sy/n);
}