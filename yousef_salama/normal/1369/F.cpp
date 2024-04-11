#include <bits/stdc++.h>
using namespace std;

const int MAXT = 100005;

int t;
long long s[MAXT], e[MAXT];

bool win(long long s, long long e){
	if(s > e)return true;
	
	if(e & 1){
		if(s & 1)return false;
		else return true;
	}else{
		if(s > e / 2){
			if(s & 1)return true;
			else return false;
		}else{
			if(s * 2 > e / 2)return true;
			else return win(s, e / 4);
		}
	}
}
bool lose(long long s, long long e){
	if(s > e)return false;
	
	if(s * 2 > e)return true;
	else return win(s, e / 2);
}

int dp[MAXT][2][2];
int solve(int i, int c, int r){
	if(i == t){
		return (c == r);
	}
	if(dp[i][c][r] != -1)return dp[i][c][r];
	
	int& ret = dp[i][c][r];
	
	int a = solve(i + 1, 0, r);
	int b = solve(i + 1, 1, r);
	
	if(c == 0){
		if(a && b)ret = 1;
		else if(!a && !b)ret = 0;
		else if(a){
			if(lose(s[i], e[i]))ret = 1;
			else ret = 0;
		}else{
			if(win(s[i], e[i]))ret = 1;
			else ret = 0;
		}
	}else{
		if(a && b)ret = 1;
		else if(!a && !b)ret = 0;
		else if(a){
			if(lose(s[i], e[i]))ret = 0;
			else ret = 1;
		}else{
			if(win(s[i], e[i]))ret = 0;
			else ret = 1;
		}
	}
	
	return ret;
}

int main(){
	/*
	int e = 30;
	for(int i = 1; i <= e; i++)
		cout << win(i, e) << ' ';
	cout << endl;
	for(int i = 1; i <= e; i++)
		cout << lose(i, e) << ' ';
	cout << endl;*/
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		scanf("%lld %lld", &s[i], &e[i]);
	
	memset(dp, -1, sizeof dp);
	printf("%d %d\n", solve(0, 0, 1), solve(0, 0, 0));
	
	return 0;
}