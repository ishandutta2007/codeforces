#include <bits/stdc++.h>
using namespace std;


using ll=long long ;
int main()
{
	int N;cin>>N;
	vector<int>v(2*N);
	for(int i=0;i<2*N;++i)cin>>v[i];

	bool place=0;
	vector<int>places(N+1);
	bool bottom_ok=false;
	for(int i=0;i<2*N;++i){
		if(v[i])places[v[i]]=i;
	}
	for(int i=N;i<2*N;++i){
		
		if(v[i]==1){
			bool ok=true;
			for(int j=i;j<2*N;++j){
				if(v[j]==j-i+1){

				}else{
					ok=false;
				}
			}
			bottom_ok=ok;
		}
	}
	int answer=-1;
	//cout<<bottom_ok<<endl;
	if(bottom_ok){
		//cout<<1<<endl;
		int place=places[1];
		bool aok=true;
		for(int i=2*N-place+1;i<=N;++i){
			if(places[i]<N+(i-(2*N-place+1))){

			}else{
				//cout<<i<<endl;
				aok=false;
			}
		}
		if(aok){
			//cout<<1<<endl;
			answer=places[1]-N;
			//cout<<answer<<endl;
		}
	}
	//cout<<answer<<endl;
	if(answer==-1){

		answer=0;
		for(int i=1;i<=N;++i){
			answer=max(answer,places[i]-N-i+2);
		}
		answer+=N;
	}
	cout<<answer<<endl;
}