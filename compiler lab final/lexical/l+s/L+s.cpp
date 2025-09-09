#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <unordered_set>

using namespace std;

// -------- Lexical helpers --------
bool isOperatorChar(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '%' || ch == '=' || ch == '<' || ch == '>' ||
            ch == '!' || ch == '&' || ch == '|');
}

bool isSpecialSymbol(char ch)
{
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

bool isKeyword(const string& word)
{
    static const unordered_set<string> keywords =
    {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for",
        "goto","if","int","long","register","return","short","signed","sizeof",
        "static","struct","switch","typedef","union","unsigned","void","volatile","while"
    };
    return keywords.count(word) > 0;
}

// -------- Syntax helpers --------
bool isBalanced(const string& expression)
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
            if (s.empty()) return false;
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

string rtrim(const string& str)
{
    size_t end = str.find_last_not_of(" \t\r\n\f\v");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

int main()
{
    // ---- Read the whole file into "code" ----
    ifstream file("code.txt");
    if (!file)
    {
        cout << "❌ Error: Could not open code.txt\n";
        return 1;
    }

    string code, line;
    while (getline(file, line))
    {
        code += line;
        code.push_back('\n');
    }
    file.close();

    // ---- Lexical Analysis ----
    int keywordCount = 0, identifierCount = 0;
    int operatorCount = 0, specialSymbolCount = 0;

    cout << "Operators:\n";
    for (size_t i = 0; i < code.size();)
    {
        if (isOperatorChar(code[i]))
        {
            // Check 2-char operators
            if (i + 1 < code.size() &&
                    ((code[i] == '+' && code[i+1] == '+') ||
                     (code[i] == '-' && code[i+1] == '-') ||
                     (code[i] == '=' && code[i+1] == '=') ||
                     (code[i] == '!' && code[i+1] == '=') ||
                     (code[i] == '&' && code[i+1] == '&') ||
                     (code[i] == '|' && code[i+1] == '|') ||
                     (code[i] == '<' && code[i+1] == '=') ||
                     (code[i] == '>' && code[i+1] == '=')))
            {
                cout << "  " << code[i] << code[i+1] << "\n";
                operatorCount++;
                i += 2;
                continue;
            }
            else
            {
                cout << "  " << code[i] << "\n";
                operatorCount++;
                i++;
                continue;
            }
        }
        i++;
    }

    cout << "\nSpecial Symbols:\n";
    for (char ch : code)
    {
        if (isSpecialSymbol(ch))
        {
            cout << "  " << ch << "\n";
            specialSymbolCount++;
        }
    }

    cout << "\nKeywords and Identifiers:\n";
    string word;
    for (size_t i = 0; i <= code.size(); ++i)
    {
        char ch = (i < code.size() ? code[i] : '\0');
        if (isalnum(static_cast<unsigned char>(ch)) || ch == '_')
        {
            word.push_back(ch);
        }
        else
        {
            if (!word.empty())
            {
                if (isKeyword(word))
                {
                    cout << "  \"" << word << "\" is a Keyword\n";
                    keywordCount++;
                }
                else
                {
                    cout << "  \"" << word << "\" is an Identifier\n";
                    identifierCount++;
                }
                word.clear();
            }
        }
    }

    cout << "\nSummary:\n";
    cout << "Total Operators: " << operatorCount << "\n";
    cout << "Total Special Symbols: " << specialSymbolCount << "\n";
    cout << "Total Keywords: " << keywordCount << "\n";
    cout << "Total Identifiers: " << identifierCount << "\n";
    int totalTokens = keywordCount + identifierCount + specialSymbolCount + operatorCount;
    cout << "Total Tokens (Keywords + Identifiers + Special Symbols + Operators): " << totalTokens << "\n";

    // ---- Syntax Check (simple) ----
    // 1) Balanced (), [], {}
    // 2) Last non-whitespace char is ';'  (matching your earlier logic)
    string trimmed = rtrim(code);

    if (!trimmed.empty() && trimmed.back() == ';')
    {
        if (isBalanced(code))
        {
            cout << "\nSyntax is correct\n";
        }
        else
        {
            cout << "\nSyntax error (unbalanced brackets)\n";
        }
    }
    else
    {
        cout << "\nMissing ';' at the end\n";
    }

    return 0;
}

