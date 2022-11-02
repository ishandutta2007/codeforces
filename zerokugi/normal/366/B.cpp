#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, k,m;
main(){
	cin >> n >> k;
	vector<int> arr(k);
	for(int i=0;i<n;i++){
		cin >> m;
		arr[i%k] += m;
	}
	int minn = 1000000000;
	int mink = 0;
	for(int i=0;i<k;i++){
		if(arr[i] < minn){
			minn = arr[i];
			mink = i;
		}
	}
	printf("%d\n", mink+1);
	return 0;
}