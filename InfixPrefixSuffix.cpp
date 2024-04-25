#include<bits/stdc++.h>
using namespace std;

// Function to convert infix expression to prefix
int precedence(char operation) {
    if(operation == '+' || operation == '-')
        return 1;
    if(operation == '*' || operation == '/')
        return 2;
    return 0;
}

string convertInfixToPrefix(string infixExpression) {
    stack<char> stackOfOperators;
    string prefixExpression;
    reverse(infixExpression.begin(), infixExpression.end());
    unordered_map<char, int> precedenceMap;
    precedenceMap['+'] = precedenceMap['-'] = 1;
    precedenceMap['*'] = precedenceMap['/'] = 2;
    for(char& character : infixExpression) {
        if(isalnum(character))
            prefixExpression += character;
        else if(character == ')')
            stackOfOperators.push(character);
        else if(character == '(') {
            while(stackOfOperators.top() != ')') {
                prefixExpression += stackOfOperators.top();
                stackOfOperators.pop();
            }
            stackOfOperators.pop();
        } else {
            while(!stackOfOperators.empty() && precedence(stackOfOperators.top()) > precedence(character)) {
                prefixExpression += stackOfOperators.top();
                stackOfOperators.pop();
            }
            stackOfOperators.push(character);
        }
    }
    while(!stackOfOperators.empty()) {
        prefixExpression += stackOfOperators.top();
        stackOfOperators.pop();
    }
    reverse(prefixExpression.begin(), prefixExpression.end());
    return prefixExpression;
}

// Function to convert prefix expression to infix
string convertPrefixToInfix(string &prefixExpression){
    stack<string> infixStack;
    for(int i = prefixExpression.size() - 1; i >= 0; i--){
        char currentCharacter = prefixExpression[i];
        if(currentCharacter == '+' || currentCharacter == '-' || currentCharacter == '*' || currentCharacter == '/'){
            string firstOperand = infixStack.top();
            infixStack.pop();
            string secondOperand = infixStack.top();
            infixStack.pop();
            infixStack.push('(' + firstOperand + currentCharacter + secondOperand + ')');
        }
        else {
            string temp(1, currentCharacter);
            infixStack.push(temp);
        }
    }
    return infixStack.top();
}

// Function to convert infix expression to postfix
int getPrecedence(char operation){
    if(operation == '+' || operation == '-') return 1;
    else if (operation == '*' || operation == '/') return 2;
    else if (operation == '^') return 3;
    else return -1;
}

string convertInfixToPostfix(string infixExpression){
    stack<char> stackOfOperators;
    string postfixExpression;
    int expressionLength = infixExpression.size();
    for(int i = 0; i < expressionLength; i++){
        char currentCharacter = infixExpression[i];
        if((currentCharacter >= 'a' && currentCharacter <= 'z') || (currentCharacter >= 'A' && currentCharacter <= 'Z') || (currentCharacter >= '0' && currentCharacter <= '9')){
            postfixExpression += currentCharacter;
        }
        else if(currentCharacter == '('){
            stackOfOperators.push(currentCharacter);
        }
        else if(currentCharacter == ')'){
            while(stackOfOperators.top() != '('){
                postfixExpression += stackOfOperators.top();
                stackOfOperators.pop();
            }
            stackOfOperators.pop();
        }
        else{
            while(!stackOfOperators.empty() && getPrecedence(currentCharacter) <= getPrecedence(stackOfOperators.top())){
                postfixExpression += stackOfOperators.top();
                stackOfOperators.pop();
            }
            stackOfOperators.push(currentCharacter);
        }
    }
    while(!stackOfOperators.empty()){
        postfixExpression += stackOfOperators.top();
        stackOfOperators.pop();
    }
    return postfixExpression;
}

// Function to convert postfix expression to infix
bool isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

string convertPostfixToInfix(string postfixExpression) {
    stack<string> stackOfOperands;
    for (char& character : postfixExpression) {
        if (isalnum(character)) {
            stackOfOperands.push(string(1, character));
        } else if (isOperator(character)) {
            string operand2 = stackOfOperands.top();
            stackOfOperands.pop();
            string operand1 = stackOfOperands.top();
            stackOfOperands.pop();
            string expression = "(" + operand1 + character + operand2 + ")";
            stackOfOperands.push(expression);
        }
    }
    return stackOfOperands.top();
}

int main() {
    string infixExpression;
    cout << "Enter the Infix Expression: ";
    cin >> infixExpression;
    cout << "Infix: " << infixExpression << endl;
    cout << "Prefix: " << convertInfixToPrefix(infixExpression) << endl;
    
    string prefixExpression;
    cout << "Enter the Prefix Expression: ";
    cin >> prefixExpression;
    cout << "Infix Expression: " << convertPrefixToInfix(prefixExpression) << endl;
    
    cout << "Enter the Infix Expression: ";
    cin >> infixExpression;
    cout << "Infix: " << infixExpression << endl;
    cout << "Postfix: " << convertInfixToPostfix(infixExpression) << endl;
    
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;
    cout << "Postfix: " << postfixExpression << endl;
    cout << "Infix: " << convertPostfixToInfix(postfixExpression) << endl;
    
    return 0;
}
