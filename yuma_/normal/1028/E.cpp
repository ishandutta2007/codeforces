#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



int main()
{
	int N;cin>>N;
	vector<long long int>v(N);
	for(int i=0;i<N;++i)scanf("%lld",&v[i]);
	long long int max_elem=*max_element(v.begin(),v.end());
	vector<int>places;
	for (int i = 0; i < N; ++i) {
		if (v[i] == max_elem) {
			places.push_back(i);
		}
	}
	int start=-1;
	for (int i = 0; i < places.size(); ++i) {
		int sa=i==places.size()-1?places[0]+(N-places[i]):places[i+1]-places[i];

		if (sa>1) {
			start=places[(i+1)%places.size()];
		}
	}
	if (max_elem == 0) {
		cout<<"YES"<<endl;
		for(int i=0;i<N;++i)printf("%d ",634573);
		cout<<endl;
		
	}
	else if (start == -1) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		bool flag=false;
		vector<long long int>nums(N);
		nums[start]=max_elem;
		int now=start;
		for (int i = 0; i < N-1; ++i) {
			int next=now-1;
			if(next==-1)next+=N;
			nums[next]=nums[now]+v[next];
			if (!flag&&v[next] == 0) {
				nums[next] *= 2;
				flag = true;
			}
			now=next;
		}
		for (int i = 0; i < N; ++i) {
			printf("%lld ",nums[i]);
		}
		cout<<endl;
	}

	return 0;

}