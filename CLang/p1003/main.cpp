#include <iostream>

using namespace std;

int T;

int fi1(int n) {
    if (n < 0 )
        return 0;
    if (n == 0) {
        //printf("0");
        return 1;
    } else if (n == 1) {
        //printf("1");
        return 0;
    } else {
        return fi1(n-1) + fi1(n-2);
    }
}
int fi2(int n) {
    if (n < 0 )
        return 0;
    if (n == 0) {
        //printf("0");
        return 0;
    } else if (n == 1) {
        //printf("1");
        return 1;
    } else {
        return fi2(n-1) + fi2(n-2);
    }
}

int main()
{
    int tmp;
    cin >> T;
    for (int i = 0 ; i < T ; ++i) {
        cin>>tmp;
        cout << fi1(tmp) << " " << fi2(tmp) << endl;
    }
    return 0;
}
