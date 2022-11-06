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
	
	
	int H,W;cin>>H>>W;
	int K;cin>>K;
	vector<string>field;
	for(int i=0;i<H;++i){
		string st;cin>>st;
		field.push_back(st);
	}

	int ans=0;
	for(int y=0;y<H;++y){
		int k=0;
		for(int x=0;x<W;++x){
			if(field[y][x]=='.'){
				k++;
			}else{
				k=0;
			}
			if(k>=K)ans++;
		}
	}	

	for(int x=0;x<W;++x){

		int k=0;
		for(int y=0;y<H;++y){
			if(field[y][x]=='.'){
				k++;
			}else{
				k=0;
			}
			if(k>=K)ans++;
		}
	}
	if(K==1)ans/=2;
	cout<<ans<<endl;
	return 0;

}