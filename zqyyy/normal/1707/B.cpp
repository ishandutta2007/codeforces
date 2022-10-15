#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}

inline void work() {
	int n=read(), c0=0; vector<int>vec;
	while (n--) {
		int x=read();
		if (x) vec.push_back(x);
		else c0++;	
	}
	while ((int)vec.size()>1) {
		vector<int>tmp; int c=0;
		for (int i=1; i<(int)vec.size(); i++) {
			int x=vec[i]-vec[i-1];
			if (x) tmp.push_back(x);
			else c++;
		}
		if (c0) c0--, tmp.push_back(vec[0]);
		c0+=c, sort(tmp.begin(), tmp.end()), vec.swap(tmp);
	}
	if (vec.empty()) puts("0");
	else printf("%d\n", vec[0]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}