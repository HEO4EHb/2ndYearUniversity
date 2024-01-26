/*
 *  алгоритм Кнута-Морриса-Пратта для поиска по образцу
 */


/*
Шаг 1
 Прикладываем левый край образца к левому краю окна
просмотра, К = 0, j = 0
 Вычисляем префикс-функцию образца
 Шаг 2
 Проверяем, входит ли образец в текст, начиная с К-й
позиции, последовательным сравнением символов образца
q[j] с символами текста s[K+j] слева направо, j=j...M-1
 Шаг 3
 Если имеем M совпадений, то образец в тексте найден –
конец работы
 Если K+M >= N, то образец в тексте не найден – конец
работы
 Иначе K = K+j-prefix[j-1], j = prefix[j-1] и переходим к шагу*/
#include <iostream>
#include <vector>
using namespace std;

//префикс-функция, которая выдает p{i} - такую наиб длину наибольшего собственного суффикса 
//(не совпадающ. со всей строкой) подстроки s[0 .. i], совпадающего с её префиксом
vector<int> getPrefixFunction(const string& s)
{
	int length = (int)s.length();
	vector<int> pi(length, 0);
	for (int i = 1; i < length; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
		{
			j = pi[j - 1];
		}
		if (s[i] == s[j])
		{
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

//реализация поиска
void getKMPSearch(const string& text, const string& substring)
{
	vector<int> pi = getPrefixFunction(substring + '#' + text);
	//определяем длину строки
	int tLength = (int)text.length();
	//с какого места ищем образец
	int sLen = (int)substring.length();
	//ищем образец
	for (int i = 0; i < tLength; i++)
	{
		if (pi[sLen + 1 + i] == sLen)
		{
			cout << i - sLen + 1 << ".." << i << "   ";
		}
	}
}

void printPrefix(const string& s)
{
	vector<int> pi = getPrefixFunction(s);
	cout << "Prefix function: ";
	for (auto elem : pi)
	{
		cout << elem << " ";
	}
	cout << "\n";
}

int main()
{
	string text, substring;
	//cout << "Enter the text" << "\n";
	text = "abracadabra";
	//cout << "Enter the sub" << "\n";
	substring = "abra";
	printPrefix(text);
	cout << "Entrance '" << text << "' into '" << substring << "' : ";
	getKMPSearch(text, substring);

	return 0;
}


//abacaba
 //abcabcd