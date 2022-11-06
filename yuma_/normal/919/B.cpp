#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;

int solve(long long int a){
	string st=(to_string(a));
	int num=0;
	for(int i=0;i<st.size();++i){
		char ch(st[i]);
		num+=ch-'0';
	}
	return num==10;
}

int main() { 
	
	int K;cin>>K;
	int num=0;
	int ans=-1;
	for(int i=0;i<2e7;++i){
		if(solve(i)){
			num++;
			if(num==K){
				ans=i;
				break;
			}
		}

	}
	cout<<ans<<endl;
	return 0;

}