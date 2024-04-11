#include <bits/stdc++.h>
#define f(a, n) for (int a = 0; a<n; a++)
#define F(a, n) for (int a = 1; a<=n; a++)
using namespace std;
int L[105], R[105];
int n;
vector<int> V;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	V.push_back(0);
	cin>>n;
	F(i, n) cin>>L[i]>>R[i];
	F(i, n) if (L[i] == 0) {
		int j = i;
		while (j != 0){
			V.push_back(j);
			j = R[j];
		}
	}
	V.push_back(0);
	F(i, n){
		L[V[i]] = V[i-1];
		R[V[i]] = V[i+1];
	}
	F(i, n) cout<<L[i]<<" "<<R[i]<<endl;
}