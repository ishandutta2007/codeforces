#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 1005;

int n, m, w[MAXN], b[MAXM];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &w[i]);
		
	vector <int> v;
	int total = 0;
	
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		
		int ind = -1, sum = 0;
		
		for(int j = 0; j < (int)v.size(); j++){
			if(v[j] == b[i]){
				total += sum;
				
				ind = j;
				break;
			}
			sum += w[v[j] - 1];
		}
		if(ind == -1){
			total += sum;
		}else{
			v.erase(v.begin() + ind);
		}
		v.insert(v.begin(), b[i]);
	}
	
	printf("%d\n", total);
	
	return 0;
}