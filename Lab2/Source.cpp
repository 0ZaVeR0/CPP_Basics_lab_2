#include <iostream>
using namespace std;

void first() {
	const int n = 10;
	int x[n];
	int s1 = 0, s2 = 0;

	for (int i = 0; i < n; i++) {
		cout << "Введите число (" << i + 1 << "/" << n << ") >> ";
		cin >> x[i];
	}
	
	for (int i = 0; i < n / 2; i++) {
		if (x[i] >= 0) { s1 += x[i]; }
	}
	for (int i = n / 2; i < n; i++) {
		if (x[i] <= 0) { s2 += x[i]; }
	}
	cout << "В первой половине массива сумма положительных элементов " << s1 << "\n";
	cout << "Во второй половине массива сумма отрицательных элементов " << s2;
}

void second() {
	// random
	//int min = -100, max = 201;

	int higest_num = 0, ans = 0;
	float temp = 0.0f;

	const int l = 12,w = 12;
	float ans2[w] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
	int matrix[w][l] = {
		{ -59, 76, 3, 69, -26, -54, -79, -88, -72, 43, -23, -95},
		{ 66, 44, 12, -11, 81, -17, -97, -91, -70, 32, -17, 53},
		{ -9, 21, 35, -77, -80, 97, -80, -82, -2, -19, -40, -87},
		{ 40, 69, 51, -55, 61, -7, 67, 83, 86, -59, -34, -27},
		{ 13, -66, -80, 7, 0, 95, 38, 96, -20, -7, 93, 75},
		{ -45, -80, -20, -67, -13, 57, 96, -2, 69, 36, 10, -13},
		{ -89, -4, -51, -26, 32, 47, -28, 31, 32, 61, 65, -45},
		{ -37, 82, 42, 40, -38, 78, -40, -22, 4, -33, 10, -69},
		{ -62, -28, -85, -41, -91, 61, -84, 11, 92, -19, 8, -5},
		{ 16, -25, 97, -98, 91, 78, -61, -100, -56, -4, -28, -70},
		{ -33, -76, 16, 44, -56, -56, 38, -3, -89, 93, -86, 45},
		{ -43, -84, -3, -87, 53, -59, 18, -19, 81, -74, -85, 32} 
		};


	/*
	    w <> l^
	    x x x x x x x x x x x x 
		o x x x x x x x x x x x
		o o x x x x x x x x x x
		o o o x x x x x x x x x
		o o o o x x x x x x x x
		o o o o o x x x x x x x
		o o o o o o x x x x x x
		o o o o o o o x x x x x
		o o o o o o o o x x x x
		o o o o o o o o o x x x
		o o o o o o o o o o x x
		o o o o o o o o o o o x 
	*/

	/*generating matrix
	for (int i = 0; i < w; i++){
		for (int j = 0; j < l; j++) {
			matrix[i][j] = (min + (rand() % max));
			// cout << "\nВведите элемент матрицы >> "
			// cin >> matrix[i][j]
		}
	}*/

	//debug output
	/*for (int i = 0; i < l; i++) {
		cout << "{ ";
		for (int j = 0; j < w; j++) {
			cout << matrix[i][j] << ", ";
		}
		cout << "},\n";
	}*/

	for (int i = 0; i < l; i++) {
		for (int j = i; j < w; j++) {
			if (abs(matrix[i][j]) > higest_num) {
				higest_num = abs(matrix[i][j]);
				ans = matrix[i][j];
			}
		}
	}

	for (int i = 0; i < w; i++) {
		temp = 0.0f;
		for (int j = 0; j < l; j++) {
			temp += (float)matrix[j][i];
		}
		temp /= w;
		ans2[i] = temp;
	}

	cout <<"Mаксимальный по модулю элемент в заштрихованной области " << ans << "\n";

	cout << "Cредние арифметические значения каждого столбца >>\n";
	for (int i = 0; i < w; i++) {
		cout << ans2[i] <<" ";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int task;
	bool running = true;

	while (running) {
		cout << "\nВведите номер задания >> ";
		cin >> task;
		switch (task)
		{
		case (1):first(); break;
		case (2):second(); break;
		case (101): running = false; break;
		default: cout << "Unknown task"; break;
		}
	}

	return 0;
}