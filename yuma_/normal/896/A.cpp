#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


string zero = "What are you doing at the end of the world? Are you busy? Will you save us?";
string l = "What are you doing while sending 5";
string m = "5? Are you busy? Will you send 5";
string r = "5?";
string one = l + zero + m + zero + r;


vector<long long int>szs(100001);
char solve(int a, long long int b) {
	if (a == 0) {
		if(zero.size()<=b)return '.';
		else return zero[b];
	}
	else {
		{
			if (szs[a]<= b) {
				return '.';
			}
			else {
				long long int sa=l.size();
				long long int sb=szs[a-1];
				long long int sc=m.size();
				long long int sd=szs[a-1];
				long long int se=r.size();
				if(b<sa)return l[b];
				else if(b<sa+sb)return solve(a-1,b-sa);
				else if(b<sa+sb+sc)return m[b-sa-sb];
				else if(b<sa+sb+sc+sd)return solve(a-1,b-sa-sb-sc);
				else {
					assert(b<sa+sb+sc+sd+se);
					return r[b-sa-sb-sc-sd];
				}
			}
		}
	}
}

signed main() {
	
	//cout<<one<<endl;
	szs[0]=zero.size();
	for (int i = 0; i < 100000; ++i) {
		szs[i+1]=szs[i]*2+l.size()+m.size()+r.size();
		if(szs[i+1]>=2e18)szs[1+i]=2e18;
	}
	int Q;cin>>Q;
	string answer;
	while (Q--) {
		int a;
		long long int b;cin>>a>>b;
		b--;
		char ch=solve(a,b);
		answer.push_back(ch);
	}
	for (auto &c : answer) {
		if(c=='5')c='\"';
	}
	cout<<answer<<endl;
	return 0;
}