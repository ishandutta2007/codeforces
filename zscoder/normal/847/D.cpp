#include <bits/stdc++.h>
#define f(a, n) for (int a = 0; a<n; a++)
#define F(a, n) for (int a = 1; a<=n; a++)
using namespace std;
multiset<int> S; //stores time to reach last plate
int n, T;
int ans;
int A[200005];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	S.insert(-1);
	cin>>n>>T;
	T--;
	F(i, n) cin>>A[i];
	F(i, min(n, T)){
		S.insert(A[i]+n-i); //time to reach last plate
		while ((*prev(S.end())) > T + n-i) S.erase((*prev(S.end())));
		ans = max(ans, (int)S.size() - 1);
	}
	cout<<ans<<endl;
}