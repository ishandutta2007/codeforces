#include <bits/stdc++.h>
#define f(a, n) for (int a = 0; a<n; a++)
#define F(a, n) for (int a = 1; a<=n; a++)
using namespace std;
pair<int, pair<int, int>> A[105];
bool B[105], C[105];
int P[105];
int n, k, m, a, x;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>k>>m>>a;
	F(i, n) A[i].second.second = i;
	F(i, a){
		cin>>x;
		A[x].first--;
		A[x].second.first = i;
	}
	sort (A+1, A+n+1);
	F(i, n) P[A[i].second.second] = i;
	int R = m-a;
	F(i, n){ //check for B
		int I = P[i];
		if ((I > k) || (A[I].first == 0)) {
			B[i] = 0;
			continue;
		}
		if (n==k){
			B[i] = 1;
			continue;
		}
		int reqvote = 0;
		for (int j = I+1; j <=k+1; j++){
			reqvote += -A[I].first +1 + A[j].first;
		}
		B[i] = (reqvote > R ? 1 : 0);
	}
	F(i, n){ //check for C
		int I = P[i];
		A[I].first -= R;
		if (R) A[I].second.first += 105;
		if ((A[I] <= A[k]) && (A[I].first < 0)) C[i] = 1;
		else C[i] = 0;
		A[I].first += R;
		if (R) A[I].second.first -= 105;
	}
	F(i, n){
		if (n==1) cout<<"1 ";
		else if (B[i]) cout<<"1 ";
		else if (C[i]) cout<<"2 ";
		else cout<<"3 ";
	}
	cout<<endl;
}