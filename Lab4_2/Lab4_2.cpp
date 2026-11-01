
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double xp, xk, dx, x, y, B;

    cout << "Enter xp: ";
    cin >> xp;

    cout << "Enter xk: ";
    cin >> xk;

    cout << "Enter dx: ";
    cin >> dx;

    if (dx <= 0 || xp > xk)
    {
        cout << "Invalid interval or step." << endl;
        return 0;
    }

    cout << fixed << setprecision(4);
    cout << "------------------------------" << endl;
    cout << "|     x     |       y        |" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; xp + i * dx <= xk + 1e-9; i++)
    {
        x = xp + i * dx;

        if (abs(x) < 1e-9)
        {
            cout << "|" << setw(10) << x
                << " |   undefined    |" << endl;
            continue;
        }

        if (x < 0)
            B = 1 + 4 * x * x;
        else if (x <= 2)
            B = pow(exp(x) + abs(x), 2);
        else
            B = 5 * sin(x * x + 1);

        y = 2 / x + abs(x) + B;

        cout << "|" << setw(10) << x
            << " |" << setw(15) << y << " |" << endl;
    }

    cout << "------------------------------" << endl;

    return 0;
}
