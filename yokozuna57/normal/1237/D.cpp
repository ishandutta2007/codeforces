#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;

#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static int n;
	static int a[200010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
		a[n+i] = a[i];
	}
	
	static int ret[200010] = {};
	int R = -1, MAX = 0;
	for(int i = 0 ; i < n ; i ++){
		if(a[i] > MAX){
			MAX = a[i];
			R = i;
		}
	}
	R += n;
	ret[R] = -1;
	for(int i = R-n+1 ; i < R ; i ++){
		if(2*a[i] < MAX){
			ret[R] = i-R+n;
			break;
		}
	}
	if(ret[R] == -1){
		for(int i = 0 ; i < n ; i ++){
			printf("-1%c",(i+1==n)?'\n':' ');
		}
		return 0;
	}
	
	//cout << R << " " << ret[R] << endl;
	
	map<int,int> M;
	for(int i = R-1 ; i >= R-n+1 ; i --){
		map<int,int>::iterator itr = M.lower_bound((a[i]+1)/2);
		if(itr == M.begin()){
			ret[i] = ret[i+1]+1;
		}
		else {
			--itr;
			ret[i] = min( ret[i+1]+1 , itr->sc-i );
		}
		while(M.size()>0){
			itr = M.end(); itr--;
			if(itr->fr >= a[i])M.erase(itr);
			else break;
		}
		M.insert(pair<int,int>(a[i],i));
	}
	
	for(int i = 0 ; i < n ; i ++){
		printf("%d%c",max(ret[i],ret[i+n]),(i+1==n)?'\n':' ');
	}
}