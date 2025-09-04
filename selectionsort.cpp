#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(vector<int> &arr){
    int n = arr.size();
    int imax;

    for(int i = 0; i < n - 1; i++){
        imax = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[imax]){
                imax = j;
            }
        }
        swap(arr[i], arr[imax]);
    }

}

int main(){
    int n;
    cout << "Masukan Jumlah Siswa :";
    cin >> n;

    vector<int> nilai(n);
    for(int i = 0; i < n; i++){
        cout << "Masukan Nilai Siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    selectionsort(nilai);

    cout << "\n===Peringkat Nilai Siswa===" << endl;
    for(int i = 0; i < n; i++){
        cout << "Ranking " << i + 1 << ": " << nilai[i] << endl;
    }
}