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
	int i = 1; //���� k �� n
	// ����� �������� ������, ����� �������� , ��� ����� ��������� �� n �� k ����� ����� ��������� �� n �� (n-k)
	// �� ���� ����� ����� �� �������� � ����� ������� ���������

	for (i; i <= (set_size - 1) / 2; ++i) {
		c += move(((fact(set_size) / (fact(set_size - i)*fact(i))) * 2));
	}
	// ��� ��, ���� ������ set-� ������ �� ������ ������ �������������� ��������� �� n �� n/2
	if ((set_size) % 2 == 0)
		c += move((fact(set_size) / (fact(set_size - i)*fact(i))));
	return c;
}
// ����� ������ ����� ���������� ��� ����� ������������ ������ ��� � ���
// ����� ��������������� ���, ��� x*y=HO�(x,y)*���(x,y)
// ������� , ��� x=���(x,y)*k, a y=���(x,y)*m, � ��������, ��� k � m ������ ���� ������� ��������, ����� ����� ��� ����� ���� k � m
// � ������� solve ������� ��� ������� �������� ����� ���(x,y)/ ���(x,y) � ��������� � ��� set
// �����, ��������� ������� ���������, ���� ��� ���������� �� ������� �����(��� � ����� ���� ������� ������� k � m) � ������� ������� count
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
		// ��������� ��� ����������� ���� (n,1) � (1,n)
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