#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int main(){
	int q;
	scanf("%d",&q);
	for(;q>0;q--){
		string s,t;
		cin>>s>>t;
		bool ok=false;
		for(int i=0;i<s.size();i++){
			if(s[i]!=t[0])continue;
			for(int j=1;j<=t.size();j++){
				bool ok_=true;
				for(int k=0;k<j;k++){
					if(i+k<s.size()&&t[k]==s[i+k]){}
					else { ok_=false; break; }
				}
				if(!ok_)continue;
				for(int k=j;k<t.size();k++){
					if(0<=i+j-2-(k-j)&&i+j-2-(k-j)<s.size()&&t[k]==s[i+j-2-(k-j)]){}
					else { ok_=false; break; }
				}
				if(ok_){ ok=true; break; }
			}
			if(ok)break;
		}
		if(ok)puts("YES");
		else puts("NO");
	}
}