#include<bits/stdc++.h>
using namespace std;
int x,ans=0;
int main(){
	scanf("%d",&x);
	while((1<<ans)<=x)ans++;
	printf("%d\n",ans);
}