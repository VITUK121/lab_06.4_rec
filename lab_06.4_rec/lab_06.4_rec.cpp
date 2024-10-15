#include <iostream>
#include <ctime>
using namespace std;

double* make_arr(int size) {
	return new double[size];
}

void fill_arr(double* arr, int size, int index) {
	if (index != size) {
		arr[index] = -10. + rand() * (10. - (-10.)) / RAND_MAX;
		fill_arr(arr, size, index+1);
	}
}

void print_arr(double* arr, int size, int index) {
	if (index != size) {
		cout << arr[index] << " ";
		print_arr(arr, size, index+1);
	}
	else {
		cout << endl;
	}
}

int min_index(double* arr, int size, int elements_index, int index) {
	if (index == size) { 
		return elements_index; 
	}
	(arr[elements_index] > arr[index]) ? (min_index(arr, size, index, index + 1)) : (min_index(arr, size, elements_index, index + 1));
}

//////////////////////////////////////////////////////////
void find(double* arr, int size, int index, int& result) {
	if (index != size) {
		if (arr[index] < 0) {
			result = index;
			return;
		}
		find(arr, size, index + 1, result);
	}
}

double sum(double* arr, int a, int b) {
	if (a != b) {
		return arr[a] + sum(arr, a + 1, b);
	}
	return 0;
}

double sum_between_two(double* arr, int size) {
	int a = -1;
	int b = -1;
	find(arr, size, 0, a);
	find(arr, size, a+1, b);

	if (a == -1 || b == -1) {
		cout << "Not enough negative numbers!" << endl;
		return -1.;
	}

	return sum(arr, a+1, b);
}
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
void fill_temp(double* arr, double* temp, int i, int &index, int size, string condition) {
	if (i != size) {
		if (condition == "<=") {
			if (fabs(arr[i]) <= 1) {
				temp[index] = arr[i];
				index++;
			}
		}
		else if (condition == ">") {
			if (fabs(arr[i]) > 1) {
				temp[index] = arr[i];
				index++;
			}
		}
	fill_temp(arr, temp, i + 1, index, size, condition);
	}
}

void copy(double* arr, double* temp, int size, int index) {
	if (index != size) {
		arr[index] = temp[index];
		copy(arr, temp, size, index + 1);
	}
}

void change_arr(double* arr, int size) {
	double* temp = new double[size];
	int index = 0;

	fill_temp(arr, temp, 0, index, size, "<=");
	fill_temp(arr, temp, 0, index, size, ">");
	
	copy(arr, temp, size, 0);

	delete[] temp;
}
//////////////////////////////////////////////////////////

int main() {
	srand(time(NULL));
	int n;
	cout << "n = "; cin >> n;

	double* a = make_arr(n);
	fill_arr(a, n, 0);
	print_arr(a, n, 0);

	cout << "min_index() = " << min_index(a, n, 0, 1) << endl;
	cout << "sum() = " << sum_between_two(a, n) << endl;
	change_arr(a, n);
	print_arr(a, n, 0);

	delete[] a;
}