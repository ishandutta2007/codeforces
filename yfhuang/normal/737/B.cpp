#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

char s[maxn];

int a,b;
int k;
int n;
int main(){
	cin >> n >> a >> b >> k;
	scanf("%s",s + 1);
	int now = 0;
	int num = 0;
	s[n + 1] = '1';
	for(int i = 1;i <= n + 1;i++){
		if(s[i] == '1'){
			num = num + now / b;
			now = 0;
		}
		else{
			now++;
		}
	}
	//cout << now << endl;
	//cout << num << endl;
	vector<int> ans;
	for(int i = 1,j = 1;i <= n && num >= a;i = j + 1,j = i){
		if(s[i] == '1') continue;
		while(j < n && s[j + 1] == '0') j++;
		for(int k = i + b - 1;k <= j;k += b){
			ans.push_back(k);
			num--;
			if(num < a) break;
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0;i < ans.size();i++){
		printf("%d",ans[i]);
		printf("%c",i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}