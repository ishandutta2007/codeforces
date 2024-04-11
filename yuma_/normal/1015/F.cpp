#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

long long int dp[201][201][201];
const long long int mod=1e9+7;
int main() {
	int N;cin>>N;
	int l_big=0;
	string st;cin>>st;
	vector<int>backs(st.size());
	for (int i = 1; i < st.size(); ++i) {
		string nst=st.substr(0,i+1);
		if(nst.back()==')')nst.back()='(';
		else nst.back()=')';
		for (int len=i;len>=0;--len) {
			if (st.substr(0, len) == nst.substr(i+1 - len, len)) {
				backs[i]=len;
				break;
			}
		}
	}
	dp[0][0][0]=1;
	for (int x = 0; x < 2 * N; ++x) {
		for (int l_num = 0; l_num < 2 * N; ++l_num) {
			for (int status = 0; status <= st.size(); ++status) {
				for (int plus = 1; plus >= -1; plus -= 2) {
					int r_num=l_num+plus;

					int next_status;
					if (status == st.size()) {
						next_status=st.size();
					}
					else {
						if (plus == 1 && st[status] == '(') {
							next_status=status+1;
						}
						else if(plus==-1&&st[status]==')'){
							next_status = status + 1;

						}
						else {
							next_status=backs[status];
						}
					}
					if (r_num >= 0) {
						dp[x+1][r_num][next_status]+=dp[x][l_num][status];
						dp[x+1][r_num][next_status]%=mod;
					}
				}
			}
		}
	}
	long long int answer=dp[2*N][0][st.size()];
	cout<<answer<<endl;
	return 0;
}