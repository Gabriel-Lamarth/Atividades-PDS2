#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {

    int num_p;
    cin >> num_p;

    vector<string> proibidas(num_p);
    unordered_map<string, int> mapa_proibidas;
    vector<int> contadores(num_p, 0);

    for (int i = 0; i < num_p; i++) {
        cin >> proibidas[i];
        mapa_proibidas[proibidas[i]] = i;
    }

    cin.ignore();

    string frase;
    getline(cin, frase);

    stringstream ss(frase);
    string palavra_lida;
    string frase_final = "";

    while (ss >> palavra_lida) {
        auto it = mapa_proibidas.find(palavra_lida);

        if (it != mapa_proibidas.end()) {
            int idx = it->second;
            contadores[idx]++;
            frase_final += string(palavra_lida.length(), '*') + " ";
        } else {
            frase_final += palavra_lida + " ";
        }
    }

    if (!frase_final.empty()) {
        frase_final.pop_back();
    }

    cout << frase_final << endl;

    for (int i = 0; i < num_p; i++) {
        cout << "Palavra " << proibidas[i] << " substituida " << contadores[i] << " vez(es).\n";
    }

    return 0;
}
