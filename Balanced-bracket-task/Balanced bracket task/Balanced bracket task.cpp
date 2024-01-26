#include <iostream>
#include <string>
#include <stack>
bool check(const std::string& expression)
{
    std::stack<char> stack;

    for (auto ch : expression) {
        switch (ch) {
        case '(':
        case '[':
        case '{':
            stack.push(ch);
            break;
        case ')':
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
            break;
        case ']':
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
            break;
        case '}':
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
            break;
        }
    }
    return stack.empty();
}
int main()
{
    std::string a = { '(','[','{','}',']',')' };
    if (check(a)) std::cout << "Right bracket sequence";
    else std::cout << "False bracket sequence";

    return 0;
}
