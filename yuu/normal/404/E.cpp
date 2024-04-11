#include <bits/stdc++.h>
using namespace std;
string s;
bool good(int lim){
	assert(lim);
	int now=0, low=0;
	for(char c: s){
		if(now==low) low--;
		if(c=='L'){
			now--;
			if(now==lim) now++;
		}
		else{
			now++;
			if(now==lim) now--;
		}
	}
	return (now==low);
}
int main(){
	cin>>s;
	if(s.back()=='R') for(char &c: s) c^='L'^'R';
	if(good(1e9)){
		cout<<"1\n";//no block
		return 0;
	}
	int low=1, high=s.size()+1, mid, res=0;
	while(low<=high){
		mid=(low+high)/2;
		if(good(mid)){
			res=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	cout<<res<<'\n';
}