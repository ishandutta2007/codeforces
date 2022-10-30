#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <cctype>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();e++)
using namespace std;
typedef long long int64;

int main(){
	int n,m;
	cin>>n>>m;
	int l=1,r=n;
	rep(i,m){
		string tmp;
		cin>>tmp;cin>>tmp;
		cin>>tmp;
		if(tmp=="left"){
			cin>>tmp;
			int x;cin>>x;
			r=min(r,x-1);
		} else {
			cin>>tmp;
			int x;cin>>x;
			l=max(l,x+1);
		}
	}
	if(l>r)cout<<-1;
	else cout<<r-l+1<<endl;
}