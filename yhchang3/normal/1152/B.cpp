#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin>>x;
	if(x&1);
	else{
		x^=1;
		ans.push_back(0);
	}
	for(int i=19;i>=0;i--){
		if((1<<i)&x)	continue;
		ans.push_back(i+1);
		x^=((1<<(i+1))-1);
		x+=1;
	}
	cout<<ans.size()*2<<endl;
	for(int i:ans)
		cout<<i<<' ';
	cout<<endl;
}