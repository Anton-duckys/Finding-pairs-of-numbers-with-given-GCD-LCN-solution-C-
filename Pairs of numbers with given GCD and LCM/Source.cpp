#include<iostream>
#include<fstream>
#include<set>
#include<time.h>
#include<chrono>
using namespace std;

long int fact(int N)
{

	if (N == 1)
		return 1;

	return N * fact(N - 1);

}

int count(int set_size) {
	int c = 0;
	int i = 1; //наши k из n
	// Чтобы ускорить работу, можно заметить , что число сочетаний из n по k равно числу сочетаний из n по (n-k)
	// То есть можно дойти до середины и потом удвоить результат

	for (i; i <= (set_size - 1) / 2; ++i) {
		c += move(((fact(set_size) / (fact(set_size - i)*fact(i))) * 2));
	}
	// так же, если размер set-а четный мы должны учесть дополнительное сочетание из n по n/2
	if ((set_size) % 2 == 0)
		c += move((fact(set_size) / (fact(set_size - i)*fact(i))));
	return c;
}
// Чтобы узнать какое количество пар чисел соответсвует данным НОК и НОД
// Нужно воспользоваться тем, что x*y=HOД(x,y)*НОК(x,y)
// Считаем , что x=НОД(x,y)*k, a y=НОК(x,y)*m, и учитывая, что k и m должны быть взаимно простыми, нужно найти все такие пары k и m
// В функции solve находим все простые делители числа НОК(x,y)/ НОД(x,y) и добавляем в наш set
// Далее, используя формулу сочетаний, ищем все комбинации из простых чисел(это и будут наши взаимно простые k и m) с помощью функции count
//


int solve(long int nod, long long int nok) {
	if (nod == nok)
		return 1;
	else if (nok%nod == 0) {
		set<int>se;
		int div = 2;
		long  int n = nok / nod;
		long int ce = 0;
		while (n > 1)
		{
			while (n % div == 0)
			{

				se.insert(div);
				n = n / div;
			}
			if (div == 2) div++;
			else div += 2;
		}

		ce += (count(se.size()));
		// Учитываем две тривиальные пары (n,1) и (1,n)
		return (ce + 2);
	}
	else return 0;
}

int main() {

	auto start = chrono::high_resolution_clock::now();
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	long long  int nod, nok;
	fin >> nod >> nok;
	fout << solve(nod, nok) << endl;
	fin.close();
	fout.close();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> dur(end - start);
	cout << dur.count() << " seconds " << endl;

	system("pause");
	return 0;
}