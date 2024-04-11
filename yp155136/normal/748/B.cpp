#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <vector>
using namespace std;

typedef pair<char,char> pcc;

map<char,int> mp;
vector<pcc> ans;

int main () {
	string a,b;
	while (cin >> a >> b) {
		mp.clear();
		ans.clear();
		if(a==b) {
			puts("0");
			continue;
		}
		int sz=a.size();
		bool check=true;
		for (int x=0;sz>x;x++) {
			if (a[x]!=b[x]) {
				if (mp[a[x]] ==0 && mp[b[x]] ==0) {
					mp[a[x]]=b[x];
					mp[b[x]]=a[x];
					ans.push_back(make_pair(a[x],b[x]));
				}
				else if (mp[a[x]] == b[x] && mp[b[x]]==a[x]) {
					;;
				}
				else {
					check=false;
				}
			}
			else if (a[x]==b[x]) {
				if (mp[a[x]]==0) mp[a[x]]=b[x];
				else if (mp[a[x]]==b[x]) ;
				else check=false;
			}
		}
		if (!check) puts("-1");
		else {
			printf("%d\n",ans.size());
			for (int x=0;ans.size()>x;x++) {
				printf("%c %c\n",ans[x].first,ans[x].second);
			}
		}
	}
}