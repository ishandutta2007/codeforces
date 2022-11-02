#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
int n;
main(){
	int i,j;
	while(cin >> n){
		int prev[100010]={0};
		map<int, int> diff;
		set<int> ignore;
		for(i=1;i<=n;i++){
			int x;
			cin >> x;
			if(diff.count(x) && diff[x] && diff[x] != i-prev[x]){
				ignore.insert(x);
				continue;
			}
			diff[x] = (prev[x]) ? i-prev[x] : 0;
			prev[x] = i;
		}
		cout << diff.size() - ignore.size() << endl;
		for(map<int, int>::iterator it=diff.begin();it!=diff.end();++it)
			if(!ignore.count((*it).first))
				cout << (*it).first << " " << (*it).second << endl;
	}
	return 0;
}