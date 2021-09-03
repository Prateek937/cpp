#include <iostream>
#include <stack>
#include <string>


bool validate_brackets(std::string expression) {
    std::stack<char> opening_brackets;
    char top;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '[' || expression[i] == '{' || expression[i] == '(') {
            opening_brackets.push(expression[i]);
            continue;
        }

        if (expression[i] == ']' || expression[i] == '}' || expression[i] == ')') {
            if (opening_brackets.empty())
                return false;

            switch  (expression[i]) {
                case ']' :
                    top = opening_brackets.top();
                    if (top == '{' || top == '(')
                        return false;
                    opening_brackets.pop();
                    break;

                case '}' :
                    top = opening_brackets.top();
                    if (top == '[' || top == '(')
                        return false;
                    opening_brackets.pop();
                    break;

                case ')' :
                    top = opening_brackets.top();
                    if (top == '{' || top == '[')
                        return false;
                    opening_brackets.pop();
                    break;
            }

        }
        
    }
    return(opening_brackets.empty());
}

bool validate_operators(std::string expression){
    
    for (int i = 0; i < expression.length(); i++){
        bool ex = (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/');
        if (ex && i != 0) {
            if (expression[i-1] == NULL || expression[i+1] == NULL)
                return false;
        }
    }

    return true;
}

int main()
{
    std::string exp[] = {"((()))","(a+b)*c","(1+2*3/2*(9-5)","[4*(2+9)/3]","(()((())()))","[(])","[2+5-1*3(3+1)]"};
    for (int i = 0; i < 7; i++ ){
    if (validate_brackets(exp[i]) && validate_operators(exp[i]))
        std::cout << exp[i] << " :  Valid"<<std::endl;
    else
        std::cout << exp[i]<< " :  Invalid"<<std::endl;
    }
    return 0;
}