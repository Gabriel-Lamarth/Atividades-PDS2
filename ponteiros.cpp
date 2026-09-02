#include <iostream>

using namespace std;

void inc(int &a, int *b, int c) {
    a++;
    *b += 1;
    c = c + 1;
}

int main() {
    int num;
    cin >> num;
    
    int *ptr = nullptr;

    int tam;
    cin >> tam;
    int *vet = new int[tam];
    
    for (int i = 0; i < tam; i++) {
        cin >> *(vet + i);
    }

    cout << &num << endl;
    cout << num << endl;
    cout << &ptr << endl;
    cout << ptr << endl;
    cout << &vet << endl;
    cout << vet << endl;
    cout << *vet << endl;

    ptr = &num;

    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr = 5;

    cout << num << endl;

    ptr = vet;

    cout << ptr << endl;
    cout << *ptr << endl;

    ptr = &vet[0];

    cout << (ptr == vet ? 'S' : 'N') << endl;

    cout << ptr << endl;
    cout << *ptr << endl;

    int *p = vet;
    int k = 0;
    while (k < tam) {
        *p *= 10;
        p++;
        k++;
    }

    for (int i = 0; i < tam; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < tam; i++) {
        cout << *(vet + i) << " ";
    }
    cout << endl;

    ptr = vet;
    for (int i = 0; i < tam; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    ptr = vet + tam - 1;

    cout << ptr << endl;
    cout << *ptr << endl;

    int **pp = &ptr;

    cout << pp << endl;
    cout << &pp << endl;
    cout << *pp << endl;
    cout << **pp << endl;

    int x, y, z;
    cin >> x >> y >> z;

    inc(x, &y, z);

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    delete[] vet;

    return 0;
}
