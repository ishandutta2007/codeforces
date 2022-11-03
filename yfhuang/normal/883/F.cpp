#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 405;

string s[maxn];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		string tmp;
		cin >> tmp;
		while(tmp.find("kh") != string::npos){
			int p = tmp.find("kh");
			string s1 = tmp.substr(0,p);
			string s2 = tmp.substr(p + 2,tmp.length() - 2 - p);
			tmp = s1 + "h" + s2;
		}
		while(tmp.find("u") != string::npos){
			int p = tmp.find("u");
			string s1 = tmp.substr(0,p);
			string s2 = tmp.substr(p + 1,tmp.length() - 1 - p);
			tmp = s1 + "oo" + s2;
		}
		s[i] = tmp;
	}	
	sort(s + 1,s + 1 + n);
	int ans = n;
	for(int i = 1;i <= n;i++){
		if(s[i] == s[i + 1])
			ans--;
	}
	cout << ans << endl;
	return 0;
}