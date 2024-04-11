#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	static int n;
	static int x[100010],y[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d%d",&x[i],&y[i]);
	}
	x[n] = x[0];
	y[n] = y[0];
	
	multiset<P> S;
	for(int i = 0 ; i < n ; i ++){
		S.insert(P(x[i+1]-x[i],y[i+1]-y[i]));
	}
	bool ret = true;
	for(int i = 0 ; i < n ; i ++){
		P p = P(x[i]-x[i+1],y[i]-y[i+1]);
		multiset<P>::iterator itr = S.find(p);
		if(itr == S.end())ret = false;
		else S.erase(itr);
	}
	if(ret)puts("YES");
	else puts("NO");
}