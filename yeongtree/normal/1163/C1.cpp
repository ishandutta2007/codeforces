////#include <algorithm>
//#include <iostream>
////#include <vector>
//#include <cstdio>
////#include <cstdint>
////#include <conio.h>
////#include <ctime>
////#include <cctype>
////#include <cstdlib>
////#include <random>
////#include <iomanip>
////#include <cmath>
////#include <cstring>
////#include <string>
////#include <queue>
////#include <set>
//
//using namespace std;
//
//int main()
//{
//    int n; scanf("%d", &n);
//
//    int **arr = (int**)malloc(sizeof(int*) * n);
//    *arr = (int*)malloc(sizeof(int) * n * n);
//    for(int i = 1; i < n; ++i)
//        *(arr + i) = *arr + i * n;
//
//    int *tmp_dx = (int*)malloc(sizeof(int) * 4);
//    *tmp_dx = 1, *(tmp_dx + 1) = 0, *(tmp_dx + 2) = -1, *(tmp_dx + 3) = 0;
//    int *tmp_dy = (int*)malloc(sizeof(int) * 4);
//    *tmp_dy = 0, *(tmp_dy + 1) = 1, *(tmp_dy + 2) = 0, *(tmp_dy + 3) = -1;
//    const int *dx = tmp_dx; tmp_dx = NULL;
//    const int *dy = tmp_dy; tmp_dy = NULL;
//
//    int cnt = 0, nx = 0, ny = 0;
//
//
//    int nx = 0, ny = 0;
//
//    free((int*)dx); free((int*)dy);
//    free(*arr); free(arr);
//
////    const int x = 0;
////    const int *p = &x;
////    cout << *p << ' ' << x << endl; // 0 0
////    *((int*)(p)) = 10;  //const   -const   
////    cout << *p << ' ' << x << endl; //10 0
////    if(p == &x) cout << "OKAY" << endl; //OKAY 
////    cout << p << ' ' << *p << ' ' << &x << ' ' << x << endl;    //0x1ed2feec 10 0x1ed2feec 0
////    int *p1 = (int*)p; cout << p1 << ' ' << *p1 << endl;    //0x1ed2feec 10
////    const int *p2 = &x; cout << p2 << ' ' << *p2 << endl;   //0x1ed2feec 10
////    char *p3 = (char*)p; cout << (int)*p3 << endl;  //10
////
////    (int&)x = 10;
////    cout << x << ' ' << *p << endl;
//
////
////    int *_p = (int*)malloc(4);
////    *_p = 1209840194;
////    unsigned char *_c1 = (unsigned char*)_p;
////    unsigned char *_c2 = (unsigned char*)_p + 1;
////    unsigned char *_c3 = (unsigned char*)_p + 2;
////    unsigned char *_c4 = (unsigned char*)_p + 3;
////
////    cout << _p << ' ' << *_p << endl;
////    cout << (void*)_c1 << ' ' << (int)*_c1 << endl;
////    cout << (void*)_c2 << ' ' << (int)*_c2 << endl;
////    cout << (void*)_c3 << ' ' << (int)*_c3 << endl;
////    cout << (void*)_c4 << ' ' << (int)*_c4 << endl;
//
//}


#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    long long x[n], y[n]; for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    bool hh[n][n]{}; for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(i != j) hh[i][j] = true;

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(!hh[i][j]) continue;

            for(int a = i; a < n; ++a)
            {
                for(int b = (a == i ? j + 1 : a + 1); b < n; ++b)
                {
                    if(!hh[a][b]) continue;

                    if(((x[i] - x[j]) * (y[a] - y[b]) == (x[a] - x[b]) * (y[i] - y[j]))
                       && ((x[i] - x[j]) * (y[i] - y[a]) == (x[i] - x[a]) * (y[i] - y[j]))) hh[a][b] = false;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(!hh[i][j]) continue;

            for(int a = i; a < n; ++a)
            {
                for(int b = (a == i ? j + 1 : a + 1); b < n; ++b)
                {
                    if(!hh[a][b]) continue;

                    if((x[i] - x[j]) * (y[a] - y[b]) != (x[a] - x[b]) * (y[i] - y[j])) ++cnt;
                }
            }
        }
    }


    cout << cnt;
}