#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;

int main(){
	static int n;
	static int a[200010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	
	static int b[2][200010];
	static int dpl[2][200010];
	static int dpr[2][200010];
	static int ans[2][200010];
	int root = 0;
	for(int i = 0 ; i < n ; i ++){
		if(a[i] == 1)root = i;
	}
	for(int i = 0 ; i < n ; i ++){
		b[0][i] = a[(root+i)%n];
		b[1][i] = a[(root+n-i)%n];
	}
	for(int t = 0 ; t < 2 ; t ++){
		vector<int> vec;
		dpl[t][0] = 1;
		ans[t][0] = 1;
		vec.push_back(0);
		for(int i = 1 ; i < n ; i ++){
			int nex = -1;
			while(vec.size() > 0 && b[t][vec[vec.size()-1]] > b[t][i]){
				int j = vec[vec.size()-1];
				if(nex == -1){
					dpr[t][j] = dpl[t][j];
					nex = j;
				}
				else {
					dpr[t][j] = max( dpr[t][nex]+1 , dpl[t][j] );
					nex = j;
				}
				vec.pop_back();
			}
			if(nex == -1){
				dpl[t][i] = 1;
			}
			else {
				dpl[t][i] = dpr[t][nex]+1;
			}
			vec.push_back(i);
			ans[t][i] = max( (int)vec.size()+dpl[t][i]-1 , ans[t][i-1] );
		}
	}
	
	/*for(int i = 0 ; i < n ; i ++){
		printf("%d ",b[0][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",dpl[0][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",dpr[0][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",ans[0][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",b[1][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",dpl[1][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",dpr[1][i]);
	}cout << endl;
	for(int i = 0 ; i < n ; i ++){
		printf("%d ",ans[1][i]);
	}cout << endl;*/
	
	int ret = 300000;
	int k = -1;
	for(int i = 0 ; i < n ; i ++){
		if(ret > max( ans[0][i] , ans[1][n-1-i] )){
			ret = max( ans[0][i] , ans[1][n-1-i] );
			k = (root+1+i)%n;
		}
	}
	cout << ret << " " << k << endl;
}