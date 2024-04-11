#include <iostream>
#include <string>
using namespace std;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)

int main(){
	int n,k;
	cin >> n >> k;
	
	int x = (n-k)/2;
	string s = "";
	while(s.size() < n){
		rep(i,x){
			s += '0';
			if(s.size() >= n)break;
		}
		if(s.size() < n)s += '1';
	}
	cout << s << endl;
}