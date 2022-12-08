#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int MX = 100005;

int A[MX], B[MX], C[MX];
int N;

int main()
{
	vector<int> ans;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	for(int i = 1; i <= N; i++) scanf("%d", B+i);
	for(int i = 1; i <= N; i++) C[i] = i;
	sort(C+1, C+N+1, [&](int l, int r){ return A[l] > A[r]; });
	ans.push_back(C[1]);
	for(int i = 2; i <= N; i+=2){
		if( i+1 > N || B[C[i]] > B[C[i+1]] ) ans.push_back(C[i]);
		else ans.push_back(C[i+1]);
	}
	printf("%d\n", ans.size());
	for(int c : ans) printf("%d ", c);
}