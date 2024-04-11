#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long double ld;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)
#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)

int main(){
	int n;
	ld x[2002],y[2002];
	scanf("%d",&n);
	rep1(i,n){
		cin >> x[i] >> y[i];
		x[i] += y[i]/10000000000.0;
	}
	
	string s;
	cin >> s;
	
	int start = 1;
	for(int i = 2 ; i <= n ; i ++){
		if(x[i] < x[start])start = i;
	}
	
	int ans[2002];
	bool used[2002];
	rep(i,2002)used[i] =false;
	ld p_x = x[start], p_y = 10000000000.0;
	ld q_x = x[start], q_y = y[start];
	ld dx = q_x-p_x, dy = q_y-p_y;
	ans[1] = start;
	used[start] = true;
	for(int i = 2 ; i <= n-1 ; i ++){
		vector<pair<ld,int>> vec;
		for(int j = 1 ; j <= n ; j ++){
			if(!used[j])vec.push_back(pair<ld,int>((dx*(x[j]-q_x)+dy*(y[j]-q_y))/(dy*(x[j]-q_x)-dx*(y[j]-q_y)),j));
		}
		sort(vec.begin(),vec.end());
		int nx;
		if(s[i-2] == 'R'){
			nx = vec[vec.size()-1].second;
		}
		else {
			nx = vec[0].second;
		}
		ans[i] = nx;
		used[nx] =true;
		p_x = q_x; p_y = q_y;
		q_x = x[nx]; q_y = y[nx];
		dx = q_x-p_x; dy = q_y-p_y;
	}
	for(int j = 1 ; j <= n ; j ++){
		if(!used[j])ans[n] = j;
	}
	for(int i = 1 ; i <= n ; i ++){
		printf("%d%c",ans[i],(i==n)?'\n':' ');
	}
}