#include<bits/stdc++.h>
using namespace std;

int n,a[7],x,y,ans=233,las,cnt;

int main(){
	cin>>n>>x>>y;
	a[1]=a[2]=a[3]=a[4]=x; a[5]=a[6]=y;
	srand(time(0));
	for (int T=10000;T--;){
		random_shuffle(a+1,a+7);
		las=cnt=0;
		for (int i=1;i<=6;++i){
			if (las<a[i]) ++cnt, las=n;
			las-=a[i];
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}