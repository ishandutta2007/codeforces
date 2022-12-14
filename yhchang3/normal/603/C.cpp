#include<bits/stdc++.h>
using namespace std;


int SGeven(int x){
	if(x<3)	return x;
	if(x&1)	return 0;
	return 1;
}

int SGodd(int x){
	if(x==4)	return 2;
	if(x<4)	return x&1;
	if(x&1)	return 0;
	int y=SGodd(x>>1);
	if(y==1)	return 2;
	else	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	int ans=0;
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(k&1)
			ans^=SGodd(x);
		else
			ans^=SGeven(x);
	}
	if(ans)
		cout<<"Kevin"<<endl;
	else
		cout<<"Nicky"<<endl;
}