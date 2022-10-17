#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static int n;
	static int a[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	for(int t = 29 ; t >= 0 ; t --){
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			if(a[i]&(1<<t))cnt ++;
		}
		if(cnt == 1){
			vector<int> vec;
			for(int i = 0 ; i < n ; i ++){
				if(a[i]&(1<<t))vec.push_back(a[i]);
			}
			for(int i = 0 ; i < n ; i ++){
				if(a[i]&(1<<t)){}
				else vec.push_back(a[i]);
			}
			for(int i = 0 ; i < vec.size() ; i ++){
				printf("%d%c",vec[i],(i+1==vec.size())?'\n':' ');
			}
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i ++){
		printf("%d%c",a[i],(i+1==n)?'\n':' ');
	}
}