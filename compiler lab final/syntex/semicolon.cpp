
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);  // take full line input

    int size = input.length();

    if (input[size - 1] == ';')
    {
        cout << "Syntax is correct";
    }
    else
    {
        cout << "Syntax error";
    }

    return 0;
}
