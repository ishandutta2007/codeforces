#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main() {
	int N;cin>>N;
	pair<int,int>answer(-1,-1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i%j == 0 && i*j > N&&i < N*j) {
				answer=make_pair(i,j);
			}
		}
	}
	if(answer.first==-1)cout<<-1<<endl;
	else cout<<answer.first<<" "<<answer.second<<endl;
	return 0; 
}