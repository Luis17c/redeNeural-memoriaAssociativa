#include <iostream>
#include <cmath>
using namespace std;

int iaMemory[4][4], i, j;

int teachMatrix() {
    //  Getting the vetor
    int vetor[4];
    for (i = 0; i < 4; i++) {
        cout << "Envie elemento " << i << " do vetor para aprendizado: ";
        cin >> vetor[i];
    }

    // Matrix learning the vetor
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            iaMemory[i][j] += vetor[i] * vetor[j];
        }
    }

    // See the matrix construction on console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << iaMemory[i][j] << "|";
        }
        cout << '\n';
    }

    return 0;
}

int check() {
    int vetor[4], matrixVetor[4], numerator, aux1, aux2;
    double iaResponse;

    numerator = 0;
    aux1 = 0;
    aux2 = 0;
    // Getting the vetor for checking
    for (i = 0; i < 4; i++) {
        cout << "Envie elemento " << i << " do vetor para checagem: ";
        cin >> vetor[i];
    };

    // Getting the IA response
    for (i = 0; i < 4; i++) {
        matrixVetor[i] = iaMemory[i][0] * vetor[i];
        for (j = 1; j < 4; j++) {
            matrixVetor[i] += iaMemory[i][j];
        };
    };
    
    // Getting the quality of the response
    for (i = 0; i < 4; i++) {
        numerator += matrixVetor[i] * vetor[i];

        aux1 += matrixVetor[i] * matrixVetor[i];
        aux2 += vetor[i] * vetor[i];
    };

    iaResponse = cos((numerator / (sqrt(aux1) * sqrt(aux2))));
    cout << "Resposta da IA é: " << iaResponse << "\n";

    return 0;
}

int main() {
    // Matrix construction
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            iaMemory[i][j] = 0;
        }
    }

    // See the matrix construction on console
    for (i = 0; i < 4; i++) {
        cout << "|";
        for (j = 0; j < 4; j++) {
            cout << iaMemory[i][j] << "|";
        }
        cout << '\n';
    }

    int menu = 1;
    while (menu == 1) {
        int choice;
        cout << "Pressione 1 para ensinar a IA. \n";
        cout << "Pressione 2 para checar se a IA reconhece. \n";
        cout << "Pressiona 3 para sair. \n";
        cin >> choice;

        switch (choice) {
            case 1: {
                teachMatrix();
                break;
            };
            case 2: {
                check();
                break;
            };
            case 3: {
                menu = 0;
            };
            break;
        };  
    };

    return 0;
}