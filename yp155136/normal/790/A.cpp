#include <iostream>
#include <stdio.h>
using namespace std;

string s[77];
int ans[77];

string name[56] = {
	"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
	"Jizz","Jizzz","Jizzzz","Alala","Adsdg","Asfgdf","Edison","Gsfg","Fkhr","Ryyy","Fjg","Yp","Na","Tt","Hgg","Jkk",
	"Vvv","Bn","My","He","Ice","Cream","Op","Po","Jh","Kj","Lm","Jb","Fffff","Yu"
};

int main () {
	int n,k;
	while (cin >>n >> k) {
		bool _1=false;
		int id=-1;
		for (int i=1;n-k+1>=i;i++) {
			cin >>s[i];
			if (s[i] == "YES")  {
				_1=true;
				id = i;
			}
		}
		if (!_1) {
			for (int i=1;n>=i;i++) {
				cout<<"Jizz";
				if (i!=n) cout<<" ";
			}
			cout<<endl;
			continue;
		}
		int _=0;
//		cout<<"id = "<<id<<endl;
		for (int i=id;id+k-1>=i;i++) {
//			cout<<"i = "<<i<<endl;
			ans[i]= _;
			_++;
		}
		int __=id+1;
		for (int i=id+k;n>=i;i++) {
//			cout<<"i = "<<i<<endl;
			if (s[__] == "YES") ans[i]=_++;
			else ans[i] = ans[i-k+1];
			__++;
		}
		__ = id-1;
		for (int i=id-1;i>=1;i--) {
			if (s[__] == "YES") ans[i]=_++;
			else ans[i] = ans[i+k-1];
//			cout<<"i = "<<i<<", __ = "<<__<<endl;
			__--;
		}
		for (int i=1;n>=i;i++) {
			if (i!=1) cout<<" ";
			cout<<name[ans[i]];
		}
		cout<<endl;
	}
}