#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 1;
bool ex[MN];
vector<int> _div[MN];
int mu[MN], cnt[MN];
int solve(int x){
	int res = 0;
	for(int it:_div[x])
		res+=mu[it]*cnt[it];
	return res;
}

void update(int x,int v){
	for(int it:_div[x])
		cnt[it]+=v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long int ans = 0;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		ex[x]=true;
		ans = max(ans,(long long int) x);
	}
	for(int i=1;i<MN;i++){
		for(int j=i;j<MN;j+=i)
			_div[j].emplace_back(i);
		if(i==1)	mu[i]=1;
		else if((i/_div[i][1])%_div[i][1])	mu[i]=-mu[i/_div[i][1]];
		else	mu[i]=0;
	}
	for(int g=1;g<=MN;g++){
		vector<int> st;
		for(int i=MN/g;i>=1;i--){
			if(ex[i*g]){
				int co = solve(i);
				while(co){
					if(gcd(i,st.back()) == 1){
						ans = max(ans, 1LL*i*st.back()*g);
						co--;
					}
					update(st.back(),-1);
					st.pop_back();
				}
				update(i,1);
				st.emplace_back(i);
			}
		}
		while(!st.empty())
			update(st.back(),-1),st.pop_back();
	}
	cout<<ans<<endl;
}