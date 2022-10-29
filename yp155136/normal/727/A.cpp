#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

int a,b;

vector<int> ans;

bool dfs(int id,vector<int> v) {
	if (id==a) {
		ans = v;
		ans.push_back(a);
		return true;
	}
	else if (id < a) return false;
	bool ret=false;
	if (id%2 == 0) {
		vector<int> tmp;
		for (auto i=v.begin();i!=v.end();i++) tmp.push_back((*i));
		tmp.push_back(id);
		ret |= dfs(id/2,tmp);
	}
	if (id%10 == 1) {
		vector<int> tmp;
		for (auto i=v.begin();i!=v.end();i++) tmp.push_back((*i));
		tmp.push_back(id);
		ret |= dfs(id/10,tmp);
	}
	return ret;
}

int main () {
	while (scanf("%d %d",&a,&b) != EOF) {
		vector<int> v;
		bool ret=dfs(b,v);
		if (!ret) puts("NO");
		else {
			puts("YES");
			printf("%d\n",ans.size());
			for (int x=ans.size()-1;x>=0;x--) {
				if (x!=ans.size()-1) printf(" ");
				printf("%d",ans[x]);
			}
			puts("");
		}
	}
}