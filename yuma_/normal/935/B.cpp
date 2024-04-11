#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
int main() { 
	int N;cin>>N;
	string st;cin>>st;
	int x=0,y=0;
	int ans=0;
	int type=-1;
	for(int i=0;i<st.size();++i){
		char ch(st[i]);
		if(ch=='U'){
			y++;
		}else{
			x++;
		}

		if(type==-1){
			if(y>x)type=0;
			else type=1;
		}else if(type==0){
			if(x>y){
				ans++;
				type=1;
			}
		}else{
			if(y>x){
				ans++;
				type=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;

}