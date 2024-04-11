#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

int pos[MAX_N];

int check1(int id,string s,int k) {
	//swwitch b to a;
	memset(pos,-1,sizeof(pos));
	int ret=0;
	int tmp=1;
	int L=0,R=-1;
	int len=s.size();
	for (int x=0;len>x;x++) {
		if (s[x]=='a') {
			R=x;
		}
		else if (s[x]=='b') {
			pos[tmp]=x;
			if (tmp>k) {
				L=pos[tmp-k]+1;
			}
			R=x;
			tmp++;
		}
		ret=max(ret,R-L+1);
//		cout<<"x="<<x<<" , L="<<L<<" , R="<<R<<endl;
	}
//	cout<<"id = "<<id<<endl;
//	cout<<"ret = "<<ret<<endl;
	return ret;
}

int check2(int id,string s,int k) {
	//swwitch b to a;
	memset(pos,-1,sizeof(pos));
	int ret=0;
	int tmp=1;
	int L=0,R=-1;
	int len=s.size();
	for (int x=0;len>x;x++) {
		if (s[x]=='b') {
			R=x;
		}
		else if (s[x]=='a') {
			pos[tmp]=x;
			if (tmp>k) {
				L=pos[tmp-k]+1;
			}
			R=x;
			tmp++;
		}
		ret=max(ret,R-L+1);
//		cout<<"x="<<x<<" , L="<<L<<" , R="<<R<<endl;
	}
//	cout<<"id = "<<id<<endl;
//	cout<<"ret = "<<ret<<endl;
	return ret;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while (cin >> n >> k) {
		string s;
		cin >> s;
		//switch b to a
		cout<<max(check1(0,s,k),check2(0,s,k)) <<endl;
	}
	//undo
}