#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;

int p[MAX_N];
string s,t;
bool _[MAX_N];

bool check(int id) {
//	cout<<"id = "<<id<<endl;
	memset(_,0,sizeof(_));
	for (int i=1;id>=i;i++) {
		_[p[i]]=1;
	}
	int sz_t = t.size()-1;
	int sz_s = s.size()-1;
	int i,j;
	for (i=1,j=1;sz_t>=i;i++) {
		while (j<=sz_s && t[i]!=s[j] || j<=sz_s&& _[j]==1) {
			j++;
		}
//		cout<<"i = "<<i<<" , j = "<<j<<endl;
		if (j <= sz_s && t[i]==s[j] && _[j]==0) {
			j++;
		}
		else break;
	}
	return i==sz_t+1;
}

int main () {
	while (cin >>s) {
		cin >> t;
		int sz=s.size();
		t=" "+t;
		s=" "+s;
		for (int i=1;sz>=i;i++) {
			scanf("%d",&p[i]);
		}
		int L=0,R=sz;  //L is the answer
		while (R-L!=1) {
			int mid=(L+R)>>1;
			if (check(mid)) L=mid;
			else R=mid;
		}
		printf("%d\n",L);
	}
}