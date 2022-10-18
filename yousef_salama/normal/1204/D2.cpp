#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

char s[MAXN], r[MAXN];
int N;

int main(){
	scanf("%s", s);
	N = strlen(s);
	
	for(int i = 0; i < N; i++)
		r[i] = '0';
	
	stack <int> stk;
	for(int i = 0; i < N; i++){
		if(s[i] == '0'){
			if(!stk.empty()){
				r[stk.top()] = '1';
				stk.pop();
			}
		}else{
			stk.push(i);
		}
	}
	
	r[N] = 0;
	printf("%s\n", r);
	
	return 0;
}