#include <bits/stdc++.h>
using namespace std;

struct Dat{
	int cnt;
	vector <int> vec;
	Dat(){}
	Dat(int cnt,vector <int> vec):cnt(cnt),vec(vec){}
};
Dat run(Dat D){
	int cnt=0;
	vector <int> vec;
	if(D.cnt>0){
		cnt=D.cnt-1;
		if(!D.vec.empty()) vec.push_back(D.vec[0]);
	}
	for(int i=0;i+1<D.vec.size();i++){
		int d=D.vec[i+1]-D.vec[i];
		if(d==0) cnt++;
		else vec.push_back(d);
	}
	sort(vec.begin(),vec.end());
	return Dat(cnt,vec);
}
void solve(){
	int n;
	scanf("%d",&n);
	vector <int> A(n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	Dat D=Dat(0,A);
	for(int i=0;i<n-1;i++) D=run(D);
	if(D.cnt>0) printf("%d\n",0);
	else printf("%d\n",D.vec[0]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}