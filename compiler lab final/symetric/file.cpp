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
    ifstream file("input.txt");

     string type1, op, type2;

    while (file >> type1 >> op >> type2)
    {
        check(type1, op, type2);
    }

    file.close();
    return 0;
}
