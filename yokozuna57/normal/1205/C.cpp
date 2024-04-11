#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 998244353;

int query(int a,int b,int c,int d){
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	fflush(stdout);
	int ret;
	cin >> ret;
	return ret;
}

int t = -1;
void solve(int a,int b){
	if(a < b){
		if(b == 2)t=a;
		else t = 1-a;
	}
	else {
		if(a == 2)t=b;
		else t=1-b;
	}
}

int main(){
	int a[52][52];
	int n;
	cin >> n;
	a[1][1] = 1;
	a[n][n] = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(i%2 == 1 && i >= 3){
			if(query(i-2,1,i,1))a[i][1] = a[i-2][1];
			else a[i][1] = a[i-2][1]^1;
		}
		if(i%2 == 0){
			if(query(i-1,1,i,2))a[i][2] = a[i-1][1];
			else a[i][2] = a[i-1][1]^1;
		}
		for(int j = 3 ; j <= n ; j ++){
			if((i+j)%2 == 1)continue;
			if(query(i,j-2,i,j))a[i][j] = a[i][j-2];
			else a[i][j] = a[i][j-2]^1;
		}
	}
	a[1][2] = 2;
	for(int i = 1 ; i <= n ; i ++){
		if(i == 2){
			if(query(1,2,3,2))a[3][2] = a[1][2];
			else a[3][2] = 5-a[1][2];
			if(query(2,1,3,2))a[2][1] = a[3][2];
			else a[2][1] = 5-a[3][2];
		}
		if(i%2 == 1 && i >= 5){
			if(query(i-2,2,i,2))a[i][2] = a[i-2][2];
			else a[i][2] = 5-a[i-2][2];
		}
		if(i%2 == 0 && i >= 4){
			if(query(i-2,1,i,1))a[i][1] = a[i-2][1];
			else a[i][1] = 5-a[i-2][1];
		}
		for(int j = 3 ; j <= n ; j ++){
			if((i+j)%2 == 0)continue;
			if(query(i,j-2,i,j))a[i][j] = a[i][j-2];
			else a[i][j] = a[i][j-2]^1;
		}
	}
	
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j+4 <= n ; j ++){
			if(a[i][j] != a[i][j+4]){
				if(a[i][j+1] == a[i][j+3]){
					if(a[i][j] == a[i][j+2]){
						if(query(i,j,i,j+3)){
							solve(a[i][j],a[i][j+3]);
						}
						else solve(a[i][j],a[i][j+3]^1);
					}
					else {
						if(query(i,j+1,i,j+4)){
							solve(a[i][j+1],a[i][j+4]);
						}
						else solve(a[i][j+1],a[i][j+4]^1);
					}
				}
				else {
					if(a[i][j] != a[i][j+2]){
						if(query(i,j,i,j+3)){
							solve(a[i][j],a[i][j+3]);
						}
						else solve(a[i][j],a[i][j+3]^1);
					}
					else {
						if(query(i,j+1,i,j+4)){
							solve(a[i][j+1],a[i][j+4]);
						}
						else solve(a[i][j+1],a[i][j+4]^1);
					}
				}
				break;
			}
		}
		if(t != -1)break;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(t != -1)break;
		for(int j = 1 ; j+4 <= n ; j ++){
			if(a[j][i] != a[j+4][i]){
				if(a[j+1][i] == a[j+3][i]){
					if(a[j][i] == a[j+2][i]){
						if(query(j,i,j+3,i)){
							solve(a[j][i],a[j+3][i]);
						}
						else solve(a[j][i],a[j+3][i]^1);
					}
					else {
						if(query(j+1,i,j+4,i)){
							solve(a[j+1][i],a[j+4][i]);
						}
						else solve(a[j+1][i],a[j+4][i]^1);
					}
				}
				else {
					if(a[j][i] != a[j+2][i]){
						if(query(j,i,j+3,i)){
							solve(a[j][i],a[j+3][i]);
						}
						else solve(a[j][i],a[j+3][i]^1);
					}
					else {
						if(query(j+1,i,j+4,i)){
							solve(a[j+1][i],a[j+4][i]);
						}
						else solve(a[j+1][i],a[j+4][i]^1);
					}
				}
				break;
			}
		}
		if(t != -1)break;
	}
	
	if(t == -1){
		if(a[1][3] == 1){
			if(a[2][3] == 2){
				if(query(1,1,2,3))t=1;
				else t=0;
			}
			else {
				if(query(1,2,3,3))t=0;
				else t=1;
			}
		}
		else {
			if(a[2][3] == 2){
				if(query(1,2,3,3))t=0;
				else t=1;
			}
			else {
				if(query(1,1,2,3))t=0;
				else t=1;
			}
		}
	}
	
	cout << "!" << endl;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(a[i][j] == 2){
				a[i][j] = t;
			}
			else if(a[i][j] == 3){
				a[i][j] = 1-t;
			}
			cout << a[i][j];
		}
		cout << endl;
	}
	fflush(stdout);
}