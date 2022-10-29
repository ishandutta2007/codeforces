#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

 int main () {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,k;
	while (cin >>n>>k) {
		map<string,int> cnt;
		for (int i=0;n>i;i++) {
			string s[4];
			cin >>s[0] >>s[1]>>s[2]>>s[3];
			string check[4]={"","","",""};
			for (int j=0;4>j;j++) {
				int sz=s[j].size();
//				cout<<"s = "<<s[j]<<endl;
				int _=0;
//				cout<<"sz = "<<sz<<endl;
				for (int y=sz-1;y>=0;y--) {
//					cout<<"y = "<<y<<endl;
					check[j] += " ";
					check[j][check[j].size()-1]=s[j][y];
					if (s[j][y] == 'a' || s[j][y]=='e'||s[j][y]=='i'||s[j][y]=='o'||s[j][y]=='u') {
						_++;
						if (_ == k) break;
					}
				}
//				cout<<"_ = "<<_<<" , check[j] = "<<check[j]<<endl;
				if (_ != k) {
//					cout<<"hehe"<<endl;
					check[j]=" ";
					check[j][0] = char('A' + j);
				}
			}
			if (check[0] == check[1] && check[1] == check[2] && check[2]==check[3]) {
				cnt["aaaa"]++;
				cnt["abab"]++;
				cnt["abba"]++;
				cnt["aabb"]++;
			}
			else if (check[0] == check[1] && check[2]==check[3]) {
				cnt["aabb"]++;
			}
			else if (check[0] == check[2] && check[1]==check[3]) {
				cnt["abab"]++;
			}
			else if (check[0] == check[3] && check[1]==check[2]) {
				cnt["abba"]++;
			}
		}
		if (cnt["aaaa"] == n) cout<<"aaaa"<<endl;
		else if (cnt["abab"] == n) cout<<"abab"<<endl;
		else if (cnt["abba"] == n) cout<<"abba"<<endl;
		else if (cnt["aabb"] == n) cout<<"aabb"<<endl;
		else cout<<"NO"<<endl;
//		cout<<"hahaend"<<endl;
	}
}