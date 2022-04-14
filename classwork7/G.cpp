#include <iostream>
#include <cstring>

struct atom {
    char name[5];
    int charge;
    int mass;

    atom(char *tname, int ch, int m) {
        strcpy(name, tname);
        charge = ch;
        mass = m;
    }

    atom(int ch, int m) {
        strcpy(name, "NO DATA");
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
    char tname[6]={'0'};
    char reac[6]={'0'};
    int charge, mass;
    for (int i = 0; i < N; i++) {
        std::cin >> tname >> mass >> charge;
        atoms[i] = atom(tname, charge, mass);
    }
    structsort(atoms, N);
    int M;
    std::cin >> M;
    for (int j = 0; j < M; j++) {
        *tname = {'0'};
        std::cin>>tname>>reac;
        int reacid=3;
        if(strcmp(reac, "beta-")==0) reacid=-1;
        else if (strcmp(reac, "beta+")==0) reacid=1;
        else if (strcmp(reac, "alpha")==0) reacid=0;
        for (int i = 0; i < N; i++) {
            if (strcmp(atoms[i].name, tname)==0){
                switch(reacid){
                    case -1:
                        charge=atoms[i].charge+1;
                        mass=atoms[i].mass;
                        break;
                    case 1:
                        charge=atoms[i].charge-1;
                        mass=atoms[i].mass;
                        break;
                    case 0:
                        charge=atoms[i].charge-4;
                        mass=atoms[i].mass-2;
                        break;
                    default:
                        std::cout<<"UNEXPECTED INPUT";
                        return 0;
                }
                atom temp=atom(charge, mass);
                bool found = false;
                for (int k = 0; k < N; k++) {
                    if (atoms[k]==temp){
                        std::cout<<atoms[k].name<<"\n";
                        found=true;
                        break;
                    }
                }
                if (!found) std::cout<<"NO DATA\n";
                }
        }
    }
}