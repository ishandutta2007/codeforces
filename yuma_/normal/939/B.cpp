#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;



int main() { 
	long long int N;int K;cin>>N>>K;

	long long int ans_id=-1;
	long long int ans_t=-1;
	long long int ans_num=-1;
	for(int i=0;i<K;++i){
		long long int a;cin>>a;
		long long int num=N/a*a;
		if(ans_num<num){
			ans_num=num;
			ans_id=i;
			ans_t=N/a;
		}
	}
	cout<<ans_id+1<<" "<<ans_t<<endl;
	return 0;

}