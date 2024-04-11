#include "bits/stdc++.h"

using namespace std;
#pragma warning(disable:4996)

int out(int a, int c) {
	cout<<"? "<<a<<" "<<c<<endl;
	fflush(stdout);
	int ans;cin>>ans;
	return ans;
}

void out2(int num,vector<int>v) {
	cout<<"!"<<endl<<num<<endl;
	for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
	cout<<endl;
	fflush(stdout);
	return ;
}

int main() {
	int N;cin>>N;
	vector<int>as(N),cs(N);
	for (int i = 0; i < N; ++i) {
		as[i]=out(0,i);
	}
	for (int i = 0; i < N; ++i) {
		cs[i]=out(i,0);
	}
	int tt=1;
	int x=0;
	while (tt < N) {
		x++;
		tt *= 2;
	}
	int ans_cnt=1;
	vector<int>ans_exa;
	vector<int>dummy(N);
	iota(dummy.begin(),dummy.end(),0);
	 {
		vector<int>v(N);
		for (int i = 0; i < N; ++i) {
			v[i]=cs[i];
		}
		ans_cnt=0;
		for (int axor = 0; axor < N; ++axor) {
			vector<int>p(v);
			vector<int>b(v);
			for(int i=0;i<N;++i)p[i]^=axor;
			{
				auto px(p);sort(px.begin(),px.end());
				if(px!=dummy)continue;
			}
			for(int i=0;i<N;++i)b[p[i]]=i;
			bool ok=true;
			for (int i = 0; i < N; ++i) {
				if((p[0]^b[i])!=as[i])ok=false;
				if((p[i]^b[0])!=cs[i])ok=false;
			}
			if (ok) {
				ans_cnt++;
				if(ans_cnt==1)ans_exa=p;
			}
		}
	}
	out2(ans_cnt,ans_exa);
	return 0;
	
}