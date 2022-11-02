#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod =1e9+7;
ll mypow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}
int main(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	vector<int> ans;
	for(int t=0;t<4;t++) {
		int aa=a,bb=b,cc=c,dd=d;
		ans.push_back(t);
		if(t==0) aa--;
		if(t==1) bb--;
		if(t==2) cc--;
		if(t==3) dd--;
		if(aa<0||bb<0||cc<0||dd<0){
			ans.clear();continue;
		}
		for(int i=1;i<a+b+c+d;i++){
			if(ans[i-1]==0){
				if(bb>0){
					bb--;ans.push_back(1);
				}
				else{
					ans.clear();break;
				}
			}
			if(ans[i-1]==3){
				if(cc>0){
					cc--;ans.push_back(2);
				}
				else{
					ans.clear();break;
				}
			}
			if(ans[i-1]==1){
				if(aa>0){
					aa--;ans.push_back(0);
				}
				else if(cc>0){
					cc--;ans.push_back(2);
				}
				else {
					ans.clear();break;
				}
			}
			if(ans[i-1]==2){
				if(dd>0){
					dd--;ans.push_back(3);
				}
				else if(bb>0){
					bb--;ans.push_back(1);
				}
				else {
					ans.clear();break;
				}
			}
		}
		if(ans.size()){
			cout<<"YES"<<endl;
			for(auto &it:ans) cout<<it<<" "; cout<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}