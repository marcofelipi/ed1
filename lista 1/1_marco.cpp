#include <iostream>
using namespace std;

main()
{
    int *p=NULL, a = 12; // a=12 *p = 0
    p = &a; // *p = 12
    *p = 3 * *p; // a = 36, *p = 36
    a -= 6 + *p; // a = 36 - (6 + 36)
                 // a = 36 - 42
                // a = -6, *p = -6
    *p = a + *p; // *p = (-6) + (-6)
                // *p = -12, a=-12
    cout << a << endl;
}
