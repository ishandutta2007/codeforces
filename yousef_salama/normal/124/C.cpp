#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
string s;
bool V[1005];
int C[26];
int main(){
    cin >> s;
    int cnt = 0;
    for(int i = 2; i <= s.size(); i++){
        if(2 * i <= s.size()){
           cnt++;
           V[i - 1] = true;	
	}else{
           bool found = false;
           for(int j = 2; j * j <= i; j++)
               found |= (i % j) == 0;
           cnt += found;
           V[i - 1] = found;   
        }
    }
    for(int i = 0; i < s.size(); i++)
        C[s[i] - 'a']++;
    int Max = 0;
    for(int i = 0; i < 26; i++)
	if(C[Max] < C[i])Max = i;
    if(C[Max] >= cnt){
        cout << "YES" << endl;
        string a;
        for(int i = 0; i < s.size(); i++)
            a += '*';
        for(int i = 0; i < s.size(); i++)
            if(V[i]){
               a[i] = (char)(Max + 'a');
               C[Max]--;
            }
        for(int i = 0; i < s.size(); i++){
            if(!V[i]){
	       for(int j = 0; j < 26; j++)
		   if(C[j] > 0){
	              a[i] = (char)(j + 'a');
		      C[j]--;
		      break;
		   }	
            }
        }
        cout << a << endl;      
    }else cout << "NO" << endl;
    return 0;
}