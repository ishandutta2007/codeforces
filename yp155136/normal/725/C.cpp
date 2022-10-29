#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 103;

vector<int> edg[MAX_N];
int cnt[MAX_N];

int main () {
	string s;
	while (cin >> s) {
//		cout << "s = "<<s<<endl;
		for (int x=0;MAX_N>x;x++) {
			edg[x].clear();
		}
		int len=s.size();
		memset(cnt,-1,sizeof(cnt));
		bool check=true;
		int id = -1,pos=-1;
		for (int x=0;len>x;x++) {
			int tmp=s[x];
			if (x>0 && s[x] == s[x-1]) {
				check=false;
				break;
			}
			if (cnt[s[x]] == -1) cnt[s[x]]=x;
			else id=s[x],pos=x;
			if (x>0) edg[s[x]].push_back(s[x-1]);
			if (x<len-1) edg[s[x]].push_back(s[x+1]);
		}
	    if (s[0] == s[26]) {
	        for (int x=0;12>=x;x++) cout<<s[x];
	        cout<<endl;
	        for (int x=25;x>=13;x--)cout<<s[x];
	        cout<<endl;
	        continue;
	    }
		if (!check) {
			puts("Impossible");
			continue;
		}
		int count=0;
		for (int x=0;MAX_N>x;x++) {
			sort(edg[x].begin(),edg[x].end());
			edg[x].resize(unique(edg[x].begin(),edg[x].end()) - edg[x].begin());
		}
		if (!check) {
			puts("Impossible");
			continue;
		}
		int dis = pos - cnt[id] - 1;
		string ans[2]={"             ","             "};
		if (dis % 2 == 1) {
			string n="                           ";
			for (int i=0;27>i;i++) {
				n[i] = s[(pos+i)%27];
			}
			s=n;
			dis=(25-dis);
			cnt[id]=0;
			pos=dis+1;
		}
		if (dis % 2 == 0) {
//			cout<<"dis = "<<dis<<endl;
//			cout<<"s = "<<s<<endl;
			int tmp=dis/2;
			int cur=cnt[id]+1;
			cur%=27;
			for (int i=12-tmp+1;12>=i;i++) {
				ans[0][i] = s[cur++];
				cur%=27;
			}
			for (int i=12;i>=12-tmp+1;i--) {
				ans[1][i] = s[cur++];
				cur%=27;
			}
			ans[0][12-tmp]=s[cur++];
			cur%=27;
			for (int i=12-tmp-1;i>=0;i--) {
				ans[0][i] = s[cur++];
				cur%=27;
			}
			for (int i=0;12-tmp>=i;i++) {
				ans[1][i] = s[cur++];
				cur%=27;
			}
			cout<<ans[0]<<endl<<ans[1]<<endl;
		}
	}
}