#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    a = a>b?a:b;
    a = a>c?c:a;
    cout << a;
    return 0;
}
