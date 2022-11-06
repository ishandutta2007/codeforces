#include"bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

#define Seg_Max_N (1<<18) 

int main() {
	int N;cin>>N;

	vector<int>as(N);
	map<int,int>ps;
	for(int i=0;i<N;++i){
		int a;
		scanf("%d",&a);
		as[i]=a;
	}
	for(int i=0;i<N;++i){
		int p;
		scanf("%d",&p);
		ps[p]++;
	}

	vector<int>anss;
	for(int i=0;i<N;++i){
		int amin=0;
		int amax=1<<30;

		int num=0;
		int a=as[i];
		for(int k=29;k>=0;--k){
			int amid((amin+amax)/2);

			{
				bool l_num=ps.lower_bound(amid)!=ps.lower_bound(amin);
				bool r_num=ps.lower_bound(amid)!=ps.lower_bound(amax);

				if(a&(1<<k)){
					if(r_num){
						amin=amid;
					}else{
						amax=amid;
					}
				}else{
					if(l_num){
						amax=amid;
					}else{
						amin=amid;
					}
				}
			}
		}
		assert(ps.find(amin)!=ps.end());

		anss.push_back(amin^a);
		ps[amin]--;
		if(ps[amin]==0)ps.erase(amin);
	}

	for(int i=0;i<N;++i){
		cout<<anss[i];
		if(i==N-1)cout<<endl;
		else cout<<" ";
	}
	
	return 0;
}