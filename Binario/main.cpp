#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool verificarSequencia(const string& palavra, char simbolo1, char simbolo2) {
    char estado = 'p';
    for (char c : palavra) {
        switch (estado) {
            case 'p':
                if (c == simbolo1)
                    estado = '1';
                else if (c == simbolo2)
                    estado = '2';
                else
                    return false; 
                break;
            case '1':
                if (c == simbolo1 || c == simbolo2)
                    estado = '1';
                else
                    return false;
                break;
            case '2':
                if (c == simbolo1 || c == simbolo2)
                    estado = '2';
                else
                    return false;
                break;
        }
    }
    return estado == '1' || estado == '2';
}

int main() {
    string filename = "arquivo.txt";
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return 1;
    }

    string palavra;
    char simbolo1 = '0'; // Caractere 1
    char simbolo2 = '1'; // Caractere 2
    while (inputFile >> palavra) {
        if (verificarSequencia(palavra, simbolo1, simbolo2)) {
            cout << palavra << " reconhecida" << endl;
        } else {
            cout << palavra << " rejeitada" << endl;
        }
    }

    inputFile.close();
    return 0;
}
