#include <iostream>
using namespace std;

int N = 3;
int M = 3;

int alfombraSierpinsky(int m[N][M], int n);

int main(int argc, const char * argv[]) {
    
    int m[N][M];
    cout << alfombraSierpinsky(m , 3);
    return 0;
}

int alfombraSierpinsky(int m[N][M], int n)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            m[i][j] = 0;
        }
    }
    
    if(n==0)
    {
        return m[N][M];
    }else{
        N = M*9;
        M = M*9;
        
        return alfombraSierpinsky(m, (n-1));
    }

}
