#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define SZ(x) ((int)(x).size())

int cnt[144];

int main () {
	string s;
	cin >> s;
	int cntt=0;
	int L=0;
	for (int i=0;SZ(s)>i;i++) {
		char now=s[i];
		if (now=='a' || now=='e' || now=='i' || now=='o' || now=='u') {
			cntt=0;
		}
		else {
			if (i>L+1) {
				memset(cnt,0,sizeof(cnt));
				cnt[s[i-2]]++;
				cnt[s[i-1]]++;
				cnt[s[i]]++;
				int ccnt=0;
				bool can=true;
				for (char ii='a';'z'>=ii;ii++) {
					if (ii=='a' || ii=='e' || ii=='o' || ii=='u' || ii=='i') {
						if (cnt[ii])can=false;
					}
					else if (cnt[ii]) ccnt++;
				}
				if (!can) continue;
				if (ccnt >= 2) {
					for (int l=L;i>l;l++) {
						cout<<s[l];
					}
					cout<<' ';
					L=i;
				}
			}
		}
	}
	for (int l=L;SZ(s)>l;l++) {
		cout<<s[l];
	}
	cout<<endl;
}