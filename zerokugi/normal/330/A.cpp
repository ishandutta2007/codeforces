#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;


int r,c;
main(){
	int i,j, rb=0,cb=0;
	char a;
	cin >> r >> c;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin >> a;
			if(a=='S'){
				rb |= 1 << i;
				cb |= 1 << j;
			}
		}
	}
//	cout << rb << " " << cb << endl;
	int ans = c*(r-__builtin_popcount(rb)) + r* (c-__builtin_popcount(cb)) - 
			(r-__builtin_popcount(rb)) * (c - __builtin_popcount(cb));
	cout << ans << endl;
	
	return 0;
}