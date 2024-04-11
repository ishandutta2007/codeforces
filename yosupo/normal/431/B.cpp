#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


vector<vector<ll> > board;

ll addv(int a,int b){
	return board[a][b]+board[b][a]; 
}

int main() {
	board=vector<vector<ll> >(5,vector<ll>(5));

	for(int y=0;y<5;y++)
	for(int x=0;x<5;x++) {
		cin >> board[y][x];
	}

	vector<int> per(5);
	for(int i=0;i<5;i++)per[i]=i;

	ll Mv=0;
	
	do{
		ll v=0;
		v+=addv(per[0],per[1]);v+=addv(per[2],per[3]);
		v+=addv(per[1],per[2]);v+=addv(per[3],per[4]);
		v+=addv(per[2],per[3]);
		v+=addv(per[3],per[4]);
		Mv=max(Mv,v);
	}while(next_permutation(per.begin(), per.end()));
	cout << Mv<<endl;
}