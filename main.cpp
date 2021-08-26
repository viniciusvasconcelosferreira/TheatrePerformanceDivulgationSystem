#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <string.h>

using namespace std;

int main() {
    int codigos[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
                     34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
                     69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
                    };
    string cargos[6] = {"ator", "cenógrafo", "figurinista", "maquiador", "sonoplasta", "iluminador"};
    int tam;
    tam = sizeof codigos / sizeof codigos[0];

    string a;
    string b;

    cout << "Digite o novo cargo: ";
    cin >> a;

    b = a;

    cout<<"O novo cargo é: "<<b<<endl;

    for(int i = 0; i < 6; i++) {
        cout<<cargos[i]<<endl;
    }


    return 0;
}
