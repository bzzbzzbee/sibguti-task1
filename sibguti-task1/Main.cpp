#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

pair<int, int> bubbleSort(vector<int>& arr);
pair<int, int> examineBubbleSort(int batchSize, vector<int> arr, string arrayState);

pair<int, int> selectionSort(vector<int>& arr);
pair<int, int> examineSelectionSort(int batchSize, vector<int> arr, string arrayState);

pair<int, int> shakerSort(vector<int>& a);
pair<int, int> examineShakerSort(int batchSize, vector<int> arr, string arrayState);

void examineSortRandom();
void examineSortAscending();

int sereiesNum(const vector<int> arr);
void printArray(vector<int> arr);
void initArray(unsigned int maxSize, vector<int>& array);
bool descending(int i, int j);
bool ascending(int i, int j);

int batch[4] = { 10, 50, 100, 200 };

int main(void) {
	srand(time(NULL));

	examineSortRandom();
	examineSortAscending();
}
void examineSortRandom() {
	string state = "Random";
	for (size_t i = 0; i < 4; i++) {
		vector<int> arr = vector<int>();
		initArray(batch[i], arr);
		vector<int> arr1 = vector<int>(arr);
		vector<int> arr2 = vector<int>(arr);

		auto insRes = examineSelectionSort(batch[i], arr, state);
		auto bubbRes = examineBubbleSort(batch[i], arr1, state);
		auto shakeRes = examineShakerSort(batch[i], arr2, state);

		if (insRes.first == bubbRes.first && bubbRes.first == shakeRes.first) {
			cout << "Sum is matching" << endl;
		}
		else {
			cout << "Sum is not matching" << endl;
		}

		if (insRes.second == bubbRes.second && bubbRes.second == shakeRes.second) {
			cout << "Series is matching" << endl;
		}
		else {
			cout << "Series is not matching" << endl;
		}
		cout << endl;
	}
	cout << "End of Random arrays" << endl << endl;
}

void examineSortAscending() {
	string state = "Ascending";
	for (size_t i = 0; i < 4; i++) {
		vector<int> arr = vector<int>();
		initArray(batch[i], arr);
		sort(arr.begin(), arr.end(), ascending);
		vector<int> arr1 = vector<int>(arr);
		vector<int> arr2 = vector<int>(arr);

		auto insRes = examineSelectionSort(batch[i], arr, state);
		auto bubbRes = examineBubbleSort(batch[i], arr1, state);
		auto shakeRes = examineShakerSort(batch[i], arr2, state);

		if (insRes.first == bubbRes.first && bubbRes.first == shakeRes.first) {
			cout << "Sum is matching" << endl;
		}
		else {
			cout << "Sum is not matching" << endl;
		}

		if (insRes.second == bubbRes.second && bubbRes.second == shakeRes.second) {
			cout << "Series is matching" << endl;
		}
		else {
			cout << "Series is not matching" << endl;
		}
		cout << endl;
	}
	cout << "End of Ascending arrays"<< endl << endl;
}

pair<int, int> examineSelectionSort(int batchSize, vector<int> arr, string arrayState) {
	cout << arrayState << " array, size = " << batchSize << endl << "Sorting with Selection sort" << endl << endl;
	auto pair = selectionSort(arr);
	cout << "M = " << pair.first  << ", C = " << pair.second << endl << endl;

	int sum = accumulate(arr.begin(), arr.end(), 0);
	int ser = sereiesNum(arr);

	return  make_pair(sum, ser);
}

pair<int, int> examineBubbleSort(int batchSize, vector<int> arr, string arrayState) {
	cout << arrayState << " array, size = " << batchSize << endl << "Sorting with Bubble sort" << endl << endl;
	auto pair = selectionSort(arr);
	cout << "M = " << pair.first << ", C = " << pair.second << endl << endl;

	int sum = accumulate(arr.begin(), arr.end(), 0);
	int ser = sereiesNum(arr);

	return  make_pair(sum, ser);
}

pair<int, int> examineShakerSort(int batchSize, vector<int> arr, string arrayState) {
	cout << arrayState << " array, size = " << batchSize << endl << "Sorting with Shaker sort" << endl << endl;
	auto pair = selectionSort(arr);
	cout << "M = " << pair.first << ", C = " << pair.second << endl << endl;

	int sum = accumulate(arr.begin(), arr.end(), 0);
	int ser = sereiesNum(arr);

	return  make_pair(sum, ser);
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

pair<int,int> selectionSort(vector<int>& arr) {
	int i, k, b;
	int m = 0, c = 0;
	int min;
	for (i = 0; i < arr.size(); i++) {
		min = i;
		for (k = i + 1; k < arr.size() -1; k++) {
			c++;
			if (arr[k] < arr[min]) min = k;
		}
		if (min != i)
		{
			swap(&arr[i], &arr[min]);
			m++;
		}
	}
	return  make_pair(m, c);
}

pair<int, int> shakerSort(vector<int>& arr) {
	int i, j, k, n = arr.size(), m = 0, c = 0;
	for (i = 0; i < n;) {
		for (j = i + 1; j < n; j++) {
			c++;
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
				m++;
			}
		}
		n--;

		for (k = n - 1; k > i; k--) {
			c++;
			if (arr[k] < arr[k - 1]) {
				swap(&arr[k], &arr[k - 1]);
				m++;
			}
		}
		i++;
	}
	return make_pair(m, c);
}

pair<int, int> bubbleSort(vector<int>& arr) {
	int m = 0, c = 0;
	int i, j, n = arr.size();

	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++) {
			c++;

			if (arr[j] > arr[j + 1]) {
				m++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	return make_pair(m, c);
}

void printArray(const vector<int> arr) {
	unsigned int i;
	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void initArray(unsigned int maxSize, vector<int>& arr) {

	for (size_t i = 0; i < maxSize; i++) {
		int num = rand() % 100 + 1;
		arr.push_back(num);
	}
}

bool ascending(int i, int j) {
	return (i < j);
}

bool descending(int i, int j) {
	return (i > j);
}

int sereiesNum(const vector<int> arr) {
	int num = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] != arr[i - 1]) {
			num++;
		}
	}
	return num;
}