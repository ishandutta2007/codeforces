#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	string s;
	cin >> s;
	
	vector<int> ret;
	int l=0,r=s.size()-1;
	while(1){
		while(l<s.size()&&s[l]==')')l++;
		while(r>=0&&s[r]=='(')r--;
		if(l<r){
			ret.push_back(l); l++;
			ret.push_back(r); r--;
		}
		else break;
	}
	sort(ret.begin(),ret.end());
	if(ret.size()==0){
		puts("0");
		return 0;
	}
	printf("1\n%d\n",(int)ret.size());
	for(int i=0;i<ret.size();i++){
		printf("%d%c",ret[i]+1,(i+1==ret.size())?'\n':' ');
	}
}