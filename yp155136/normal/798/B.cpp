#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main () {
	int n;
	cin >> n;
	string sss[n];
	for (int i=0;n>i;i++) {
		cin >>sss[i];
	}
	int ret[n];
	int ans=123456789;
	for (int kk=0;n>kk;kk++) {
		string s[n];
		for (int i=0;n>i;i++) {
			s[i] = sss[i];
		}
		memset(ret,0,sizeof(ret));
		bool okay=true;
		for (int i=0;n>i;i++) {
			int cnt=0;
			if (s[i] == s[kk]) {
				ret[i]=0;
				continue;
			}
			while (cnt != s[kk].size()) {
				char a=s[i][0];
				s[i].erase(s[i].begin(),s[i].begin()+1);
				s[i] +=" ";
				s[i][s[i].size()-1]=a;
				cnt++;
				if (s[i] == s[kk]) {
					ret[i] = cnt;
					break;
				}
			}
			if (cnt == s[kk].size()) okay=false;
		}
		if (!okay) {
			puts("-1");
			return 0;
		}
		else {
			int mx=0;
			for (int i=0;n>i;i++) {
				mx += ret[i];
				//cout<<"ret["<<i<<"] = "<<ret[i]<<" , mx = "<<mx<<endl;
			}
			for (int i=0;s[kk].size()>=i;i++) {
				for (int j=0;n>j;j++) {
					ret[j] ++;
					ret[j] %= (int)s[kk].size();
				}
				int tmp=0;
				for(int j=0;n>j;j++) {
					tmp += ret[j];
					//cout<<"ret["<<j<<"] = "<<ret[j]<<" , kk = "<<kk<<" , tmp = "<<tmp<<endl;
				}
				mx = min(mx,tmp);
			}
			ans = min(ans,mx);
		}
	}
	cout<<ans<<endl;
}