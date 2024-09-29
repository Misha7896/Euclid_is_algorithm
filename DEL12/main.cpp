#include <iostream>
#include <utility>	// ��� std::pair
#include <chrono>	// ��� �������

using namespace std;
using namespace chrono;

int Evklid(int a, int b);
int classFun(int a, int b);

const int lenght = 1000;

int main() {
	int res = 0;			// ���������� ��� �������� ����������
	int res2 = 0;			// ���������� ��� �������� ����������
	int mas[lenght];		// ���������� ������ ���������� ��� ������� ������

	for (int i = 0; i < lenght; i++)
		mas[i] = rand() % 1000;
	//for (int i = 0; i < lenght; i++)
	//	cout << i + 1 << ") " << mas[i] << endl;


	auto start2 = chrono::steady_clock::now();
	for (int i = 0; i < lenght - 1; i++) {
		res2 = classFun(mas[i], mas[i + 1]);
		//cout << mas[i] << " + " << mas[i + 1] << " = " << res << endl;
	}
	auto finish2 = chrono::steady_clock::now();

	// �������� �������
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < lenght - 1; i++) {
		res = Evklid(mas[i], mas[i + 1]);
		//cout << mas[i] << " + " << mas[i + 1] << " = " << res << endl;
	}
	auto finish = chrono::steady_clock::now();


	// ������� ������� ����� �������� � ��������� �������� ������� � �������������
	cout << "\nTime 1: " << duration_cast<nanoseconds>(finish - start).count() << " nano" << endl;
	cout << "res1 = " << res << endl;	// ������� ���������


	cout << "\nTime 2: " << duration_cast<nanoseconds>(finish2 - start2).count() << " nano" << endl;
	cout << "res2 = " << res2 << endl;	// ������� ���������




	return 0;
}

// �������� �������
int Evklid(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

int classFun(int a, int b) {
	int res = 0;
	for (int i = 1; i < a && i < b; i++) {
		if ((a / float(i) == a / i) && (b / float(i) == b / i))
			res = i;
	}
	return res;
}