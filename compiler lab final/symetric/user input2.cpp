#include <bits/stdc++.h>
using namespace std;

void check(string type1, string op, string type2)
{
    if (type1 != type2)
    {
        cout << "syntax error: " << type1 << " " << op << " " << type2 << endl;
    }
    else
    {
        cout << "syntax correct: " << type1 << " " << op << " " << type2 << endl;
    }
}

int main()
{
    string type1, op, type2;

    cout << "Enter first type: ";
    cin >> type1;

    cout << "Enter operator (+,-,*,/): ";
    cin >> op;

    cout << "Enter second type: ";
    cin >> type2;

    check(type1, op, type2);

    return 0;
}

