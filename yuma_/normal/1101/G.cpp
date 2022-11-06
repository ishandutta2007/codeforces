#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

void add(vector<int>&v, int a) {
	int now=a;
	for (int i = 29; i >= 0; --i) {
		if (now&(1 << i)) {
			if (v[i] == -1) {
				v[i]=now;
				return ;
			}
			else {
				now^=v[i];
			}
		}
	}
}
int main() {
	int now_xor=0;
	vector<int>v(30,-1);
	int N;cin>>N;
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d",&a);
		now_xor^=a;
		add(v,now_xor);
	}
	int answer=count_if(v.begin(),v.end(),
		[](const int a) {
		return a != -1; });

	if(now_xor==0)answer=-1;
	cout<<answer<<endl;
	return 0;
}