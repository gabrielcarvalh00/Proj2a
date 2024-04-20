#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool verificarSequencia(const string& sequencia) {
    char estado = 'p';
    for (char c : sequencia) {
        switch (estado) {
            case 'p':
                if (c >= '0' && c <= '9')
                    estado = '1';
                else
                    return false;
                break;
            case '1':
                if (c >= '0' && c <= '9')
                    estado = '1';
                else
                    return false;
                break;
        }
    }
    return estado == '1';
}


int main() {
    string nomeArquivo = "input.txt";
    ifstream arquivoEntrada(nomeArquivo);

    if (!arquivoEntrada) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return 1;
    }

    string sequencia;
    while (arquivoEntrada >> sequencia) {
        if (verificarSequencia(sequencia)) {
            cout << sequencia << " reconhecida" << endl;
        } else {
            cout << sequencia << " rejeitada" << endl;
        }
    }

    arquivoEntrada.close();
    return 0;
}
