#include <iostream>
#include <random>
#include <fstream>

const int N = 100 + 2;
//states of cells: 0-empty 1-free 2-fixed

void fix(int state[N]) {
    for (int i = 1; i < N - 1; i++) if (state[i] == 1 && (state[i - 1] || state[i + 1])) state[i] = 2;
}//fixes any free cells that fit the requirements

int move(int state[N], int K, std::uniform_int_distribution<int> distr, std::mt19937 &generator) {
    int temp[N] = {0};
    int moved = 0;
    for (int i = 1; i < N - 1; i++) {
        if (state[i] == 1) {
            moved = 1;

            int tempint = distr(generator);
            int dir1 = 0;
            switch (tempint) {
                case 0:
                    dir1 = 1;
                    break;
                case 1:
                    dir1 = -1;
                    break;
                case 2:
                    dir1 = 1;
                    break;
                case 3:
                    dir1 = -1;
                    break;
                default:
                    std::cout << "fuck, line 32";
                    return 0;
            }//unpacks the one random integer into a horisontal movement

            if (temp[i + dir1]) temp[i] = 1;
            else temp[i + dir1] = 1;
        }
    }
    for (int i = 1; i < K - 1; i++) state[i] = temp[i];
    return moved;
}//moves any free cells, returns 0/1 whether any were moved

int step(int state[N], int K, std::uniform_int_distribution<int> distr, std::mt19937 &generator) {
    int a = move(state, K, distr, generator);
    fix(state);
    return a;
}//completes a full step of the simulation


int main() {
    std::ofstream myfile("experiment4.csv", std::ios_base::app);
    std::uniform_int_distribution<int> spawner(1, 100);

    for (int frac = 1; frac <= 100; frac += 1) {
        myfile << "frac:" << frac << ';';
        std::cout << "frac:" << frac << ';';
        for (int K = 102; K <= N; K += 2) {
            myfile << "size:" << K - 2 << ';';
            std::cout << "size:" << K - 2 << ';';
            for (int seed = 1; seed < 1000; seed++) {

                std::mt19937 generator(seed);
                std::uniform_int_distribution<int> distr(0, 3);

                int state[N] = {0};//generates a square array that's 2 elements wider than the crystal in each direction
                int time = 0;

                for (int i = 0; i < frac; i++) {
                    int j = spawner(generator);
                    if (state[j]) i--;
                    state[j] = 1;
                }
                //spawn the appropriate amount of dislocations
                /*state[K-1] = 2;
                state[(K-1)/2]=1;
                state[0]=2;*/
                fix(state);//fixes the already connected dislocations

                while (step(state, K, distr, generator)) {
                    time += 1;
                }//runs the simulation
                myfile << time << ';';
            }
            myfile << '\n';
        }
    }
    myfile.close();
    return 0;
}
