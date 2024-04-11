#include <iostream>
using namespace std;

int Map[1002][1002];
int main () {
	int n;
	cin >> n;
	int max=0;

	for (int i=0;n>i;i++) {
		int a,b;
		cin >> a >> b;
		Map[a][b]=1;
		if (a>max)max=a;
		if (b>max)max=b;
	}
	n=1000;
	long long int ans=0;
	for (int y=1;n>=y;y++) {   //search for y=x+?
		int x=1;
		int ty=y;
		long long int tmp=0;
		while (n>=ty) {
			//cout << x << ' ' << ty << endl;
			if (Map[x][ty]==1) tmp++;
			x++;
			ty++;
		}
		if (tmp>1) ans+=(tmp)*(tmp-1)/2;
	}
	
	for (int x=2;n>=x;x++) {   //search for y=x+?
		int y=1;
		int tx=x;
		long long int tmp=0;
		while (n>=tx) {
			//cout << tx << ' ' << y << endl;
			if (Map[tx][y]==1) tmp++;
			tx++;
			y++;
		}
		if (tmp>1) ans+=(tmp)*(tmp-1)/2;
	}
	
	for (int y=1;n>=y;y++) {   //search for y=x+?
		int x=n;
		int ty=y;
		long long int tmp=0;
		while (n>=ty) {
			//cout << x << ' ' << ty << endl;
			if (Map[x][ty]==1) tmp++;
			x--;
			ty++;
		}
		if (tmp>1) ans+=(tmp)*(tmp-1)/2;
	}
	
	for (int x=n-1;x>=1;x--) {   //search for y=x+?
		int y=1;
		int tx=x;
		long long int tmp=0;
		while (tx>=0) {
			//cout << tx << ' ' << y << endl;
			if (Map[tx][y]==1) tmp++;
			tx--;
			y++;
			//if (tmp==2) cout << "$$$ " << tx << ' ' << y << endl;
		}
		if (tmp>1) ans+=(tmp)*(tmp-1)/2;
	}
	
	cout << ans << endl;
}

/*
5
1 3
1 5
2 4
1 1
3 4
@.@.@
...@.
...@.
.....
.....
*/