#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int a1,a2,a3;cin>>a1>>a2>>a3;
		int b1,b2,b3,b4,b5;cin>>b1>>b2>>b3>>b4>>b5;
		a1-=b1,a2-=b2,a3-=b3;
		if(a1<0||a2<0||a3<0){
			cout<<"NO"<<endl;
			continue;
		}
		int tmp1=min(a1,b4);
		int tmp2=min(a2,b5);
		a1-=tmp1,b4-=tmp1;
		a2-=tmp2,b5-=tmp2;
		if(b4+b5<=a3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}