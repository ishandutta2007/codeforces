#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int cnt[2] = {};
	for(int i = 0 ; i < n ; i ++){
		if(s[i] == 'z')cnt[0] ++;
		if(s[i] == 'n')cnt[1] ++;
	}
	
	vector<int> ret;
	for(int i = 0 ; i < cnt[1] ; i ++)ret.push_back(1);
	for(int i = 0 ; i < cnt[0] ; i ++)ret.push_back(0);
	for(int i = 0 ; i < ret.size() ; i ++){
		if(i+1 == ret.size())printf("%d\n",ret[i]);
		else printf("%d ",ret[i]);
	}
}