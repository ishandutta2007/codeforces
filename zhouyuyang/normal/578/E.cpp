#include<bits/stdc++.h>
#define N 100005
using namespace std;
char s[N];
set<int> S[2];
vector<int> tp,ans;
int main(){
	scanf("%s",s);
	int n=strlen(s),cnt=0;
	for (int i=0;i<n;i++)
		S[s[i]=='L'].insert(i);
	while (!S[0].empty()||!S[1].empty()){
		cnt++;
		if (S[0].empty()){
			ans.push_back(*S[1].begin());
			S[1].erase(S[1].begin());
			continue;
		}
		if (S[1].empty()){
			ans.push_back(*S[0].begin());
			S[0].erase(S[0].begin());
			continue;
		}
		int cs=*S[0].begin()>*S[1].begin();
		if (cnt==1){
			if (S[1].size()>S[0].size()) cs=1;
			if (S[1].size()<S[0].size()) cs=0;
		}
		int now=*S[cs].begin(),la=cs;
		tp.resize(0);
		for (;;){
			set<int>::iterator it;
			it=S[cs].lower_bound(now);
			if (it==S[cs].end()) break;
			la=cs; now=*it;
			tp.push_back(now);
			S[cs].erase(it); cs^=1;
		}
		if (S[la].size()&&(S[la^1].empty()||(*S[la].begin()<*S[la^1].begin()))){
			for (int j=0;j<tp.size()-1;j++)
				ans.push_back(tp[j]);
			S[la].insert(tp.back());
		}
		else
			for (int j=0;j<tp.size();j++)
				ans.push_back(tp[j]);
	}
	printf("%d\n",cnt-1);
	for (int i=0;i<ans.size();i++)
		printf("%d ",ans[i]+1);
}