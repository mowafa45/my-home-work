#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_set>

using namespace std;

unordered_set<string> keywords = {
    "int", "float", "if", "else", "while", "return", "for", "void", "char", "double"
};

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=';
}

bool isSeparator(char ch) {
    return ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}';
}

bool isKeyword(const string& str) {
    return keywords.count(str);
}

bool isNumber(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

void lexer(const string& input) {
    int i = 0;
    int n = input.length();

    while (i < n) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (isalpha(input[i]) || input[i] == '_') {
            string word;
            while (i < n && (isalnum(input[i]) || input[i] == '_')) {
                word += input[i++];
            }

            if (isKeyword(word))
                cout << word << " : Keyword\n";
            else
                cout << word << " : Identifier\n";

        } else if (isdigit(input[i])) {
            string num;
            while (i < n && isdigit(input[i])) {
                num += input[i++];
            }
            cout << num << " : Number\n";

        } else if (isOperator(input[i])) {
            cout << input[i++] << " : Operator\n";

        } else if (isSeparator(input[i])) {
            cout << input[i++] << " : Separator\n";

        } else {
            cout << input[i++] << " : Unknown Token\n";
        }
    }
}

int main() {
    string code = "int a = 10 + b;";
    cout << "Input Code: " << code << "\n\nTokens:\n";
    lexer(code);
    return 0;
}