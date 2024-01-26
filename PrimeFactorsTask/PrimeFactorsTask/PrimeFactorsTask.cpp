#include <iostream>
using namespace std;
//маитматеческая задачка
void primeFactors(int n)
{
    //делим на 2 чтобы проперить является ли число чётным
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }

    // n уже точно нечётное так что мы можем пропустить один элемент 
    //  ( i = i +2) то есть делим сейчас на все нечётные числа до i<=sqrt
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // пока n делится на i, выводим  i и делим  n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }

    // это на случай когда n 
    // это простое число большее чем 2 
    if (n > 2)
        cout << n << " ";
}

int main()
{
    int n;
    cin >> n;    
    primeFactors(n);
    return 0;
}