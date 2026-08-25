// Conta vogais de uma palavra inserida na entrada
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string palavra;
    cin >> palavra;

    vector<int> letras(5);

    for (auto elemento: palavra) {
        switch (elemento) {
            case 'a':
                letras[0]++;
                break;
            case 'e':
                letras[1]++;
                break;
            case 'i':
                letras[2]++;
                break;
            case 'o':
                letras[3]++;
                break;
            case 'u':
                letras[4]++;
                break;
        }
    }

    char vog;

    for (int i {0}; i < 5; i++){
        if (letras[i] > 0){
            switch (i){
                case 0:
                    vog = 'a';
                    break;
                case 1:
                    vog = 'e';
                    break;
                case 2:
                    vog = 'i';
                    break;
                case 3:
                    vog = 'o';
                    break;
                case 4:
                    vog = 'u';
                    break;
            }
            cout << vog << ' ' << letras[i] << endl;
        }
    }
    return 0;
}
