#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

int main(){
	string s;
	cin >> s;
	cout << s;
	reverse(s.begin(),s.end());
	cout << s << endl;
}