#include <iostream>
#include <random>
#include <fstream>

const int N = 100 + 2;
//states of cells: 0-empty 1-free 2-fixed

int minfrac = 0;
int maxfrac = 100;
int minsize = 11+2;
int maxsize = 20+2;

void fix(int state[N][N], int K) {
    for (int i = 1; i < K - 1; i++)
        for (int j = 1; j < K - 1; j++)
            if (state[i][j] == 1 &&
                (state[i - 1][j] || state[i][j - 1] ||
                 state[i][j + 1] || state[i + 1][j]))
                state[i][j] = 2;

}//fixes any free cells that fit the requirements

int move(int state[N][N], int K, std::uniform_int_distribution<int> distr, std::mt19937 &generator) {
    int temp[N][N] = {0};
    int moved = 0;
    for (int i = 1; i < K - 1; i++)
        for (int j = 1; j < K - 1; j++) {
            if (state[i][j] == 1) {
                moved = 1;

                int tempint = distr(generator);
                int dir1 = 0;
                int dir2 = 0;
                switch (tempint) {
                    case 0:
                        dir1 = 1;
                        break;
                    case 1:
                        dir1 = -1;
                        break;
                    case 2:
                        dir2 = 1;
                        break;
                    case 3:
                        dir2 = -1;
                        break;
                    default:
                        std::cout << "fuck, line 32";
                        return 0;
                }//unpacks the one random integer into a vertical and horisontal movement

                if (temp[i + dir1][j + dir2]) temp[i][j] = 1;
                else temp[i + dir1][j + dir2] = 1;

            }
        }
    for (int i = 1; i < N - 1; i++) for (int j = 1; j < N - 1; j++) state[i][j] = temp[i][j];
    return moved;
}//moves any free cells, returns 0/1 whether any were moved

int step(int state[N][N], int K, std::uniform_int_distribution<int> distr, std::mt19937 &generator) {
    int a = move(state, K, distr, generator);
    fix(state, K);
    return a;
}//completes a full step of the simulation

void populate(int state[N][N], int K, int frac, std::uniform_int_distribution<int> spawner, std::mt19937 &generator){
    int numtospawn = (K-2)*(K-2)*frac/100;
    for (int i=0; i<numtospawn; i++){
        int a = spawner(generator);
        int b = spawner(generator);
        if(state[a][b]) i--;
        state[a][b]=1;
    }
}

void setup(int state[N][N], int K, int frac, std::uniform_int_distribution<int> spawner, std::mt19937 &generator){
    if (!frac) state[(K - 1) / 2][(K - 1) / 2] = 1;
    else populate(state, K, frac, spawner, generator);
    for (int i = 0; i <K-1; i++) {
        state[i][0] = 2;
        state[0][i] = 2;
        state[i][N - 1] = 2;
        state[N - 1][i] = 2;
    }//sets all the borders to 2
    fix(state, K);//fixes the already connected dislocations
}

int main() {
    std::ofstream myfile("experiment5.csv", std::ios_base::app);
    std::uniform_int_distribution<int> distr(0, 3);

    int state[N][N] = {0};//generates a square array that's 2 elements wider than the crystal in each direction
    for (int size=minsize; size<=maxsize; size++) {
        std::uniform_int_distribution<int> spawner(1, size-2);
        for(int frac=minfrac; frac<=maxfrac; frac++) {
            myfile << "size:" << size - 2 << ';';
            myfile << "frac:" << frac << ';';
            for (int seed = 1; seed < 1000; seed++) {
                std::mt19937 generator(seed);
                int time = 0;
                setup(state, size, frac, spawner, generator);
                while (step(state, size, distr, generator)) {
                    time += 1;
                }//runs the simulation
                myfile << time << ';';
            }
            myfile << '\n';
        }
        std::cout<<size-2<<'\n';
    }
    myfile.close();
    return 0;
}
