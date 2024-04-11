#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int sum = 0;
    for (int i=1;i<=n;i++){
	char c;
	cin >> c;
	if (c == '8'){
	    sum++;
	}
    }
    cout << min(n / 11,sum) << endl;
    return 0;
}