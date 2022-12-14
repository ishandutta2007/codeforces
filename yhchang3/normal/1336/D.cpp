#include<bits/stdc++.h>
using namespace std;

int by,bz;

pair<int,int> ask(int x){
	cout<<"+ "<<x<<endl;
	int y,z;
	cin>>y>>z;
	int dy = y-by;
	int dz = z-bz;
	by = y;
	bz = z;
	return make_pair(dy,dz);
}

int ans[101];
void guess(int n){
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<' '<<ans[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>by>>bz;
	auto q1 = ask(1), q2 = ask(2),q3 = ask(3),q4 = ask(1);
	ans[1] = floor(sqrt(q4.first * 2 + 1e-8));
	if(q2.second == 0 )	ans[3]=0;
	else	ans[3] = floor(sqrt(q3.first*2 + 1e-8)) + 1;
	ans[2] = q4.second / (ans[3]+1) - 1;
	int pre = q3.second;
	for(int i=4;i<=n;i++){
		if(i==n){
			pre/=(ans[i-2]+1);
			ans[i]=pre-ans[i-3]-1;
		}
		else{
			auto q = ask(i);
			pre -= (ans[i-3]+1)*(ans[i-2]+1);
			if(pre == 0)
				ans[i] = 0;
			else
				ans[i] = floor(sqrt(q.first*2+1e-8)) + 1;
			pre = q.second;
		}
	}
	guess(n);
}