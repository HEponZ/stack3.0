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

	cout << "������� ������: ";
	getline(cin, buf, ';');

    try
    {
        for (char symbol : buf)
        {
            if (symbol == '[' || symbol == '{' || symbol == '(')
            {
                stack.push(symbol);
            }
            else if (!stack.empty() && ((symbol == ')' && stack.top() == '(') ||
                (symbol == ']' && stack.top() == '[') ||
                (symbol == '}' && stack.top() == '{')))
            {
                stack.pop();
            }
            else if(symbol == ')' || symbol == ']' || symbol == '}')
            {
                throw logic_error("�������� ����������� ������\n");
            }
        }
        if (!stack.empty())
        {
            throw logic_error("�������� ����������� ������\n");
        }
        cout << "��� ������!\n";
    }
    catch (const logic_error& exc)
    {
        cout << exc.what() << "\n";
    }

	return 0;
}