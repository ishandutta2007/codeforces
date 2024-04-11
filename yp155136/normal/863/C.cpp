#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 6;

int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];

int Alice[MAX_N][MAX_N];
int Bob[MAX_N][MAX_N];

int last[MAX_N][MAX_N];

int main () {
	long long k;
	int a,b;
	cin >> k >>a >> b;
	int n=3;
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			cin >>A[i][j];
		}
	}
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			cin >>B[i][j];
		}
	}
	Alice[1][3] = 1;
	Alice[3][2] = 1;
	Alice[2][1] = 1;
	Bob[1][2] = 1;
	Bob[2][3] = 1;
	Bob[3][1] = 1;
	if (k<= 1000000) {
		int cnt1=0;
		int cnt2=0;
		while (k--) {
			cnt1 += Alice[a][b];
			cnt2 += Bob[a][b];
			int aa=A[a][b];
			int bb=B[a][b];
			a=aa;
			b=bb;
		}
		cout<<cnt1<< ' '<<cnt2<<endl;
	}
	else {
		int kk=1000000;
		LL cnt1=0;
		LL cnt2=0;
		for (int i=1;kk>=i;i++) {
			cnt1 += Alice[a][b];
			cnt2 += Bob[a][b];
			int aa=A[a][b];
			int bb=B[a][b];
			last[a][b] = i;
			a=aa;
			b=bb;
		}
		LL now = kk+1;
		int llast = last[a][b];
		LL sz = (now-llast);
		LL count1=0,count2=0;
		int aaa=a,bbb=b;
		do {
			count1 += Alice[aaa][bbb];
			count2 += Bob[aaa][bbb];
			int aa=A[aaa][bbb];
			int bb=B[aaa][bbb];
			aaa = aa;
			bbb = bb;
		} while (aaa!=a || bbb!=b);
		LL times=(k-now+1)/sz;
		cnt1 += times*count1;
		cnt2 += times*count2;
		now = kk + times*sz;
		while (now != k) {
			cnt1 += Alice[a][b];
			cnt2 += Bob[a][b];
			int aa=A[a][b];
			int bb=B[a][b];
			a=aa;
			b=bb;
			now++;
		}
		cout<<cnt1<< ' '<<cnt2<<endl;
	}
}