#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,x,y;

bool okay(int t) {
	return (t==y || t==(x^y));
}

bool ask(vector<int> a) {
	if (a.empty()) return false;
	printf("? %d",(int)a.size());
	for (int i:a) printf(" %d",i);
	puts("");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return okay(ret);
}

int solve(vector<int> v) {
	int l=0,r=v.size()-1;
	while (r!=l) {
		int mid=(l+r)>>1;
		vector<int> a;
		for (int i=l;mid>=i;i++) {
			a.push_back(v[i]);
		}
		if (ask(a)) r=mid;
		else l=mid+1;
	}
	return v[l];
}

int main () {
	scanf("%d %d %d",&n,&x,&y);
	int dif=0;
	int dif_bit;
	for (int i=0;9>=i;i++) {
		vector<int> a;
		for (int j=1;n>=j;j++) {
			if (((1<<i)&j) != 0) {
				a.push_back(j);
			}
		}
		if (ask(a)) {
			dif |= (1<<i);
			dif_bit = i;
		}
	}
//	cout<<" , dif = "<<dif<<" , dif_bit = "<<dif_bit<<endl;
	vector<int> va,vb;
	for (int i=1;n>=i;i++) {
		if ((i&(1<<dif_bit))) va.push_back(i);
		else vb.push_back(i);
	}
	int ans1,ans2;
	if (va.size() > vb.size()) ans1=solve(vb);
	else ans1=solve(va);
	ans2 = ans1^dif;
	printf("! %d %d\n",min(ans1,ans2),max(ans1,ans2));
	fflush(stdout);
}