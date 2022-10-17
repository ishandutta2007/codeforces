#include <iostream>
using namespace std;

int main(){
	static int n;
	static int a[100010];
	static int b[100010];
	static int exi[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&b[i]);
		exi[b[i]] = i;
	}
	
	int las = 0;
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++){
		if(exi[a[i]] < las)cnt ++;
		las = max( las , exi[a[i]] );
	}
	cout << cnt << endl;
}