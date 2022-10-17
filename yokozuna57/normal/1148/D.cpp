#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)


int main(){
	static int n;
	static int a[300010],b[300010];
	scanf("%d",&n);
	rep1(i,n)scanf("%d%d",&a[i],&b[i]);
	
	int cnt[2] = {};
	rep1(i,n){
		if(a[i] < b[i])cnt[0] ++;
		else cnt[1] ++;
	}
	if(cnt[0] > cnt[1]){
		vector<P> vec;
		rep1(i,n){
			if(a[i] < b[i])vec.push_back(P(-a[i],i));
		}
		sort(vec.begin(),vec.end());
		printf("%d\n",cnt[0]);
		for(int i = 0 ; i < vec.size() ; i ++){
			printf("%d%c",vec[i].second,(i+1==vec.size())?'\n':' ');
		}
	}
	else {
		vector<P> vec;
		rep1(i,n){
			if(a[i] > b[i])vec.push_back(P(b[i],i));
		}
		sort(vec.begin(),vec.end());
		printf("%d\n",cnt[1]);
		for(int i = 0 ; i < vec.size() ; i ++){
			printf("%d%c",vec[i].second,(i+1==vec.size())?'\n':' ');
		}
	}
}