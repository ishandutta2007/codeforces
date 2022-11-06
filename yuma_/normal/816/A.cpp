#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int af;

	
	string st;cin>>st;
	int k=stoi(st.substr(3,2));
	int h=stoi(st.substr(0,2));
	int m=stoi(st.substr(3,2));
	int ans=0;
	while(true){
		if((h%10==m/10)&&(h/10==m%10))break;
		else{
			m++;
			if(m==60){
				h++;
				m-=60;
				if(h==24)h=0;
			}
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}