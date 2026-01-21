#include <iostream>
using namespace std;

void mergeIt(int a[], int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;

    int* x = new int[n1];
    int* y = new int[n2];

    for (int i = 0; i < n1; i++)
        x[i] = a[s + i];

    for (int j = 0; j < n2; j++)
        y[j] = a[m + 1 + j];

    int i = 0, j = 0, k = s;

    while (i < n1 && j < n2) {
        if (x[i] <= y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }

    while (i < n1)
        a[k++] = x[i++];

    while (j < n2)
        a[k++] = y[j++];

    delete[] x;
    delete[] y;
}

void mergeSort(int a[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(a, s, m);
        mergeSort(a, m + 1, e);
        mergeIt(a, s, m, e);
    }
}

int main() {
    int a1[] = {12, 11, 13, 5, 6, 7};
    int n1 = 6;

    int a2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = 7;

    mergeSort(a1, 0, n1 - 1);
    mergeSort(a2, 0, n2 - 1);

    cout << "Sorted first array: ";
    for (int i = 0; i < n1; i++)
        cout << a1[i] << " ";

    cout << endl;

    cout << "Sorted second array: ";
    for (int i = 0; i < n2; i++)
        cout << a2[i] << " ";

    cout << endl;

    return 0;
}
