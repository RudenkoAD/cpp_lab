#include <iostream>
#include <cstring>

struct atom {
    char name[20];
    int charge;
    int mass;

    atom(char *tname, int ch, int m) {
        for (int i = 0; tname[i] != '\0'; ++i) {
            name[i] = tname[i];
        }
        charge = ch;
        mass = m;
    }

    atom() {
        strcpy(name, "Undefined");
        charge = -1;
        mass = -1;
    }

    bool operator<(atom oth) {
        if (mass > oth.mass) {
            return false;
        } else if (mass == oth.mass and charge > oth.charge) return false;
        return true;
    }

    bool operator>(atom oth) {
        if (mass < oth.mass) {
            return false;
        } else if (mass == oth.mass and charge < oth.charge) return false;
        return true;
    }

    bool operator==(atom oth) {
        return (mass == oth.mass) and charge==oth.charge;
    }
};

template<typename T>
void structsort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int main() {
    int N;
    std::cin >> N;
    atom *atoms = new atom[N];
    char name[20];
    char reac[20];
    int charge, mass;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> charge >> mass;
        atoms[i] = atom(name, charge, mass);
    }
    structsort(atoms, 20);
    int M;
    std::cin >> M;
    for (int j = 0; j < M; j++) {
        std::cin>>name>>reac;
        for (int i = 0; i < N; i++) {
            if (atoms[i].name == name){
                switch(reac){
                    case "beta-":
                        charge=atoms[i].charge+1;
                        mass=atoms[i].mass;
                        break;
                    case "beta+":
                        charge=atoms[i].charge-1;
                        mass=atoms[i].mass;
                        break;
                    case "alpha:":
                        charge=atoms[i].charge-2;
                        mass=atoms[i].mass-4;
                        break;
                }
                atom temp=atom("temp", charge, mass);
                for (int k = 0; k < N; k++) {
                    if (atoms[k]==temp)
                }
                }
        }
    }

}