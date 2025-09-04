#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int prmry = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > prmry)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = prmry;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}