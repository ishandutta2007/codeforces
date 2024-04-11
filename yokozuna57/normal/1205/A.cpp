#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 998244353;

int main(){
	int n;
	cin >> n;
	if(n%2 == 1){
		puts("YES");
		for(int i = 0 ; i < n ; i ++){
			printf("%d ",1+2*i+(i&1));
		}
		for(int i = 0 ; i < n ; i ++){
			printf("%d%c",1+2*i+(1-(i&1)),i==n-1?'\n':' ');
		}
	}
	else puts("NO");
}