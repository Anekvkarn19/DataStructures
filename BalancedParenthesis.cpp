 #include <iostream>
using namespace std;
int main() {
    char exp[100];
    char stack[100];
    int top = -1;
    cout << "Enter expression: ";
    cin >> exp;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {  
                cout << "Not Balanced";
                return 0;
            }
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }
    if (top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}

