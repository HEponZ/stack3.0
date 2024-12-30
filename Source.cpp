#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	stack<char> stack;
	string buf;
	char buf_char, open_braket;

	cout << "Введите строку: ";
	getline(cin, buf, ';');

	for (size_t i{ 0 }; i < buf.size(); i++)
	{
		//Записывем в переменную буфер_символ один знак из строки
		buf_char = buf[i];
		//Проверка - является ли текущий символ открывающей скобкой
		if (buf_char == '[' || buf_char == '{' || buf_char == '(')
		{
			//Если является то записываем его в стек
			stack.push(buf_char);
		}
		//Если нет, то проверяем - является ли этот символ закрывающей скобкой
		else if (buf_char == ']' || buf_char == '}' || buf_char == ')')
		{
			//Условия на проверку скобок одного вида, 
			// если открывающая такая - ( то закрывающая такая - )
			if (buf_char == ']')
			{
				open_braket = '[';
			}
			else if (buf_char == '}')
			{
				open_braket = '{';
			}
			else if (buf_char == ')')
			{
				open_braket = '(';
			}
			//Проверка пуст ли стек или последняя скобка не является открывающей
			if (stack.empty() || stack.top()!= open_braket)
			{
				cout << "Скобок не хватает\n";
				return 0;
			}
			//Если у скобки есть её пара, удаляем последнюю открывающую скобку
			stack.pop();
		}
	}
	//Если в стеке не осталось ни одной скобки, все хорошо, если осталась хоть одна
	//открывающая скобка, значит у нее нет пары
	cout << "Все хорошо!\n";

	return 0;
}