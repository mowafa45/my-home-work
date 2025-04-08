1. Header Files

#include <iostream>
This includes the input/output stream library, allowing you to use functions like cout to print text to the console.


#include <string>
Includes the string library, which lets you work with std::string type for handling text.


#include <vector>
Adds support for dynamic arrays (std::vector), though in this specific code it's not used.


#include <cctype>
Provides functions for working with characters like isdigit(), isalpha(), isspace() etc.


#include <unordered_set>
Adds support for unordered_set, which is like a hash set. It lets you quickly check if a word is in a list (like keywords).

 2. Namespace

using namespace std;
Avoids writing std:: before standard functions and objects (e.g., cout instead of std::cout).

 3. Define C++ Keywords

unordered_set<string> keywords = {
    "int", "float", "if", "else", "while", "return", "for", "void", "char", "double"
};
This is a set of reserved keywords in C++. These words have special meaning in the language and can't be used as identifiers.

 4. Helper Function: isOperator

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=';
}
Checks if the character is a simple operator like +, -, *, /, or =.

Returns true if yes, otherwise false.

 5. Helper Function: isSeparator

bool isSeparator(char ch) {
    return ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}';
}
Checks if a character is a separator used in C++ (like semicolon ;, commas, brackets, etc.).

 6. Helper Function: isKeyword

bool isKeyword(const string& str) {
    return keywords.count(str);
}
Checks if a word (string) exists in the keywords set.

Returns true if it’s a keyword, otherwise false.

 7. Helper Function: isNumber

bool isNumber(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}
Loops through every character in a string to check if they are all digits.

Used to identify a number token.

 8. Main Lexer Function

void lexer(const string& input) {
This function takes a string of code and analyzes it to find tokens like keywords, identifiers, operators, etc.


    int i = 0;
    int n = input.length();
i is the index for scanning the input string.

n stores the total length of the input.

 9. Start Scanning the Input

    while (i < n) {
Loop through each character in the input string until the end.

 10. Skip Whitespace
   if (isspace(input[i])) {
            i++;
            continue;
        }
If the current character is a space or tab or newline, skip it.

 11. Handle Identifiers or Keywords

        if (isalpha(input[i]) || input[i] == '_') {
Checks if the character is a letter or underscore (_). This starts an identifier or keyword.

       string word;
            while (i < n && (isalnum(input[i]) || input[i] == '_')) {
                word += input[i++];
            }
Collects the rest of the word (letters, numbers, underscores).


            if (isKeyword(word))
                cout << word << " : Keyword\n";
            else
                cout << word << " : Identifier\n";
Checks if the word is a keyword or just an identifier and prints its type.

 12. Handle Numbers
   } else if (isdigit(input[i])) {
            string num;
            while (i < n && isdigit(input[i])) {
                num += input[i++];
            }
            cout << num << " : Number\n";
If it starts with a digit, collect all digits to make a number and print it.

 13. Handle Operators

        } else if (isOperator(input[i])) {
            cout << input[i++] << " : Operator\n";
Checks if the character is an operator and prints it.

14. Handle Separators

        } else if (isSeparator(input[i])) {
            cout << input[i++] << " : Separator\n";
Checks if the character is a separator and prints it.

15. Handle Unknown Tokens

        } else {
            cout << input[i++] << " : Unknown Token\n";
        }
    }
}
If the character doesn't fit into any of the known categories, it's marked as Unknown.

 16. Main Function

int main() {
The starting point of every C++ program.


    string code = "int a = 10 + b;";
A sample input string that mimics a line of C++ code.


    cout << "Input Code: " << code << "\n\nTokens:\n";
Prints the input code and a label before token output.


    lexer(code);
Calls the lexer function to analyze the sample code.


    return 0;
}
Indicates that the program ended successfully.
Sample Output
When running this code with the input "int a = 10 + b;", the output will be:


int : Keyword
a : Identifier
= : Operator
10 : Number
+ : Operator
b : Identifier
; : Separator

