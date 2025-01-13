#include <iostream>
#include <stack>
#include <string>
#include <exception>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	stack<char> stack;
	string buf;

	cout << "Введите строку: ";
	getline(cin, buf, ';');

    try
    {
        for (char symbol : buf)
        {
            if (symbol == '[' || symbol == '{' || symbol == '(')
            {
                stack.push(symbol);
            }
            else if (symbol == ')' || symbol == ']' || symbol == '}')
            {

                if (stack.top() == '(' || stack.top() == '[' || stack.top() == '{')
                {
                    stack.pop();
                }
                else
                {
                    throw logic_error("Скобок не хватает\n");
                }
            }
        }
        if (!stack.empty()) 
        {
            throw logic_error("Скобок не хватает\n");
        }
        cout << "Все хорошо!\n";
    }
    catch (const logic_error& exc)
    {
        cout << exc.what() << "\n";
    }

	return 0;
}