#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n;
long long h[MAXN];

int main(){
	scanf("%d", &n);
	
	int a = -1;
	for(int i = 2; i <= n; i++){
		if(a == -1)a = i;
		else{
			printf("2 1 %d %d\n", a, i);
			fflush(stdout);
			
			int s;
			scanf("%d", &s);
			
			if(s == -1)a = i;
		}
	}
	
	int mx = -1;
	for(int i = 2; i <= n; i++)if(i != a){
		printf("1 1 %d %d\n", a, i);
		fflush(stdout);
		
		scanf("%lld", &h[i]);
		
		if(mx == -1 || h[mx] < h[i])mx = i;
	}
	
	vector < pair <long long, int> > v, w;
	for(int i = 2; i <= n; i++)if(i != a && i != mx){
		printf("2 1 %d %d\n", mx, i);
		fflush(stdout);
		
		int s;
		scanf("%d", &s);
		
		if(s == 1)w.push_back(make_pair(h[i], i));
		else v.push_back(make_pair(h[i], i));
	}
	
	sort(v.begin(), v.end());
	sort(w.rbegin(), w.rend());
	
	printf("0 1 %d", a);
	for(pair <long long, int> x : v)
		printf(" %d", x.second);
	printf(" %d", mx);
	for(pair <long long, int> x : w)
		printf(" %d", x.second);
	printf("\n");
	
	return 0;
}