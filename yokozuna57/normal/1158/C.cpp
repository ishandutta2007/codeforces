#include <iostream>
#include <vector>
using namespace std;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)
#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)

int Next[500010];
int ans[500010];
bool solve(int a,int b,int c,int d){
	vector<int> vec;
	int loc = a;
	while(loc < b){
		vec.push_back(loc);
		loc = Next[loc];
	}
	if(loc > b)return false;
	rep(i,vec.size()){
		ans[vec[i]] = d-vec.size()+1+i;
	}
	vec.push_back(b);
	int nc = c;
	int nd = d-vec.size();
	bool ret = true;
	for(int i = 0 ; i+1 < vec.size() ; i ++){
		ret &= solve(vec[i]+1,vec[i+1],nc,nc+(vec[i+1]-vec[i]-2));
		nc += vec[i+1]-vec[i]-1;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int testcase = 0 ; testcase < t ; testcase++){
		int n;
		scanf("%d",&n);
		rep1(i,n){
			scanf("%d",&Next[i]);
			if(Next[i] == -1)Next[i] = i+1;
		}
		if(!solve(1,n+1,1,n))puts("-1");
		else {
			rep1(i,n)printf("%d%c",ans[i],(i==n)?'\n':' ');
		}
	}
}