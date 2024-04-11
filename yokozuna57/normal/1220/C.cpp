#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

int main(){
	static string s;
	cin >> s;
	
	int loc[26];
	for(int i = 0 ; i < 26 ; i ++){
		loc[i] = s.size();
		for(int j = 0 ; j < s.size() ; j ++){
			if(s[j]-'a' < i){
				loc[i] = j;
				break;
			}
		}
	}
	for(int i = 0 ; i < s.size() ; i ++){
		if(loc[s[i]-'a'] < i)printf("Ann\n");
		else printf("Mike\n");
	}
}