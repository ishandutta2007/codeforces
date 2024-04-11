#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
char a[100][100];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) a[i][j]='.';
		for (i=1;i<=n&&m;i+=2) a[i][i]='R',--m;
		if (m) {cout<<"-1\n";continue;}
		for (i=1;i<=n;i++) {for (j=1;j<=n;j++) cout<<a[i][j];cout<<'\n';}
	}
}