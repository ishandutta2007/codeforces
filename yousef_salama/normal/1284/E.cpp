#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2505;

struct point{
	long long x, y;
	point(){}
	point(long long x, long long y): x(x), y(y){}
};

bool operator <(point a, point b){
	if(a.x >= 0 && b.x < 0)return true;
	if(a.x < 0 && b.x >= 0)return false;
	
	return (a.x * b.y - a.y * b.x > 0);
}

int n;
point p[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &p[i].x, &p[i].y);
		
	long long res = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 4 / 3 / 2;
	for(int i = 0; i < n; i++){
		vector <point> v;
		for(int j = 0; j < n; j++)
			if(i != j)v.push_back(point(p[j].x - p[i].x, p[j].y - p[i].y));
		sort(v.begin(), v.end());
		
		int k = 1, r = 0;
		for(int j = 0; j < n - 1; j++){
			if(k == j){
				k = (k + 1) % (n - 1);
				r = 0;
			}
			
			while((v[j].x * v[k].y - v[j].y * v[k].x) > 0){
				k = (k + 1) % (n - 1);
				r++;
			}
			
			if(r >= 3)res -= 1LL * r * (r - 1) * (r - 2) / 3 / 2;
			
			r--;
		}
	}
	printf("%lld\n", res);
	return 0;
}