#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 106;

string s[MAX_N];
string ss[MAX_N];

bool __(int i,int id,int n) {
	string a=s[i];
	string b=s[i+1];
	a.resize(id);
	b.resize(id);
	return a==b;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while (cin >> n >> m) {
		bool _=1;
		for (int i=0;n>i;i++) {
			cin >>s[i];
			s[i] = "a" + s[i];
			if (i>0) _ &= (s[i]>=s[i-1]);
		}
		if(n==1 || _) {
			cout<<"0"<<endl;
			continue;
		}
		m++;
		int cnt=0;
		int id=1;
		while (true) {
			bool change=false;
			for (int i=0;n-1>i;i++) {
				if (s[i][id] > s[i+1][id] && __(i,id,n) ) {
					change=true;
				}
			}
			if (!change) id++;
			else {
				cnt++;
				for(int i=0;n>i;i++) {
					for (int j=id;m-1>j;j++) {
						swap(s[i][j],s[i][j+1]);
					}
					s[i].resize(m-1);
				}
				m--;
				bool _=true;
				for (int i=0;n-1>i;i++) {
					_ &= (s[i+1] >= s[i]);
				}
				if (_) break;
			}
//			cout<<"haha : "<<endl;
//			for (int i=0;n>i;i++) {
//				cout<<s[i]<<endl;
//			}
//			cout<<"END !!! "<<endl;
		}
		cout<<cnt<<endl;
	}
}