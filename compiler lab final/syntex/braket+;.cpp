
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &expression)
{
    stack<char> s;
    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    ifstream file("input.txt");
    if (!file)
    {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string input, line;
    while (getline(file, line))
    {
        input += line + "\n";
    }
    file.close();


    while (!input.empty() && isspace(input.back()))
    {
        input.pop_back();
    }

    if (!input.empty() && input.back() == ';')
    {
        if (isBalanced(input))
        {
            cout << "Syntax is correct" << endl;
        }
        else
        {
            cout << "Syntax error" << endl;
        }
    }
    else
    {
        cout << "Missing ';' at the end" << endl;
    }

    return 0;
}
