#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

bool f(int x){
	for(int i=2;x!=1;i++){
		if(i*i>x)i=x;
		if(x%i==0){
			int cnt=0;
			while(x%i==0){
				x/=i;
				cnt++;
			}
			if(cnt&1)return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		scanf("%d",&n);
		bool ok=false;
		if(n%2==0&&f(n/2))ok=true;
		if(n%4==0&&f(n/4))ok=true;
		if(ok)puts("YES");
		else puts("NO");
	}
}