#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;

int L[MAX_N],R[MAX_N];

int cha[4*MAX_N];
int now[4*MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	vector<int> v;
	for (int i=1;n>=i;i++) {
		scanf("%d %d",&L[i],&R[i]);
		v.push_back(L[i]);v.push_back(L[i]-1);
		v.push_back(R[i]);v.push_back(R[i]+1);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end()) - v.begin());
	for (int i=1;n>=i;i++) {
		L[i] = lower_bound(v.begin(),v.end(),L[i]) - v.begin() + 1;
		R[i] = lower_bound(v.begin(),v.end(),R[i]) - v.begin() + 1;
//		cout<<"i = "<<i<<"  : "<<"("<<L[i]<<","<<R[i]<<") "<<endl;
	}
	for (int i=1;n>=i;i++) {
		cha[L[i]]++;
		cha[R[i]+1]--;
	}
	int nn=4*MAX_N-1;
	int pre=0;
	v.clear();
	for (int i=1;nn>=i;i++) {
		pre += cha[i];
		now[i] = pre;
		if (pre == 1) {
//			cout<<"ha"<<" , i = "<<i<<endl;
			v.push_back(i);
		}
	}
	for (int i=1;n>=i;i++) {
		if (upper_bound(v.begin(),v.end(),R[i]) - lower_bound(v.begin(),v.end(),L[i]) == 0) {
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}