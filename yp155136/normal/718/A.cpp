#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

const int MAX_N = 2e5 + 6;

int main () {
	string i;
	int n;
	int t;
	while (cin >> n >> t ) {
		cin >> i;
		deque<int> sta;
		int pos=-1;
		int isdot=0;
		for (int x=0;n>x;x++) {
			if (i[x] == '.') isdot=x;
			else if ('5'<=i[x] && i[x]<='9' && x!=0 && isdot) {
				pos=x;
				break;
			}
		}
		if (pos==-1) {
			cout<<i<<endl;
			continue;
		}
		else {
			t--;
			bool check=false;
			for (int x=pos-1;x>=0;x--) {
				if (i[x]=='.') {
					continue;
				}
				else if (i[x]=='9') {
					check=true;
					i[x]='0';
					if (x==0) {
						string j=i;
						i = "1"+j;
						pos++;
						isdot++;
						n++;
					}
				}
				else {
					i[x] += 1;
					break;
				}
			}
			pos--;
			if (i[pos]=='.') pos--;
			if (t==0 || i[pos]!='5' || pos==0 || pos<isdot) {
				bool check=false;
				bool dot=false;
				for (int x=0;n>x;x++) {
					if (x==pos) {
						check=true;
						cout<<i[x];
						if (dot) break;
					}
					else if (i[x]=='.') {
						dot=true;
						if (x==pos || check) break;
						else cout<<i[x];
					}
					else if (!check) cout<<i[x];
					else cout<<"0";
				}
				cout<<endl;
				continue;
			}
			else {
				while (t>0 &&pos>isdot) {
					t--;
					pos--;
					if (i[pos] == '.') pos--;
					if (i[pos] == '9') {
						while (i[pos]=='9') {
							if (pos==0) {
								string j=i;
								i = "1"+j;
								n++;
								isdot++;
								break;
							}
							pos--;
							i[pos+1]='0';
						}
						if (pos==0) break;
					}
					i[pos] += 1;
					if (pos==0) break;
					else if (i[pos]!='5') break;
				}
				bool check=false;
				bool dot=false;
				for (int x=0;n>x;x++) {
					if (x==pos) {
						check=true;
						cout<<i[x];
						if (dot) break;
					}
					else if (i[x]=='.') {
						dot=true;
						if (x==pos || check) break;
						else cout<<i[x];
					}
					else if (!check) cout<<i[x];
					else cout<<"0";
				}
				cout<<endl;
				continue;
			}
		}
	}
}