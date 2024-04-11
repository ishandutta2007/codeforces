//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <complex>

using namespace std;

int N;
int main(){
    scanf("%d", &N);
    if((N % 2) == 0){
        int N_ = N / 2 - 1;
        for(int i = 0; N_ >= (1 << i); i++)
            N_ -= (1 << i);
        printf("%d\n", N_);
    }else{
        printf("%d\n", N / 2);
    }
    
    return 0;
}