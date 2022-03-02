#include <iostream>
#include <random>
#include <fstream>

const int N = 1+2;
//states of cells: 0-empty 1-free 2-fixed

void fix(int state[N][N]){
    for (int i=1; i<N-1; i++) for (int j=1; j<N-1; j++) if(state[i][j]==1&&(state[i-1][j]||state[i][j-1]||state[i][j+1]||state[i+1][j])) state[i][j]=2;

}//fixes any free cells that fit the requirements

int move(int state[N][N], std::uniform_int_distribution<int> distr, std::mt19937 &generator){
    int temp[N][N] = {0};
    int moved=0;
    for (int i=1; i<N-1; i++) for (int j=1; j<N-1; j++){
        if(state[i][j]==1){
            moved=1;

            int tempint = distr(generator);
            int dir1 = 0;
            int dir2 = 0;
            switch(tempint){
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
                    std::cout<<"fuck, line 32";
                    return 0;
            }//unpacks the one random integer into a vertical and horisontal movement

            if (temp[i+dir1][j+dir2]) temp[i][j]= 1;
            else temp[i+dir1][j+dir2] = 1;

        }
    }
    for (int i=1; i<N-1; i++) for (int j=1; j<N-1; j++) state[i][j]=temp[i][j];
    return moved;
}//moves any free cells, returns 0/1 whether any were moved

int step(int state[N][N], std::uniform_int_distribution<int> distr, std::mt19937 &generator){
    int a = move(state, distr, generator);
    fix(state);
    return a;
}//completes a full step of the simulation


int main() {
    std::ofstream myfile ("experiment.csv", std::ios_base::app);
    std::uniform_int_distribution<int> spawner(0, 100);

    //for (int frac = 1; frac<=100; frac+=1) {
        //myfile << "frac:" << frac << ';';
        myfile<<"size:"<<N-2<<';';
        for (int seed = 1; seed < 10000; seed++) {

            std::mt19937 generator(seed);
            std::uniform_int_distribution<int> distr(0, 3);

            int state[N][N] = {0};//generates a square array that's 2 elements wider than the crystal in each direction
            int time = 0;

            /*for (int i = 0; i < frac; i++) {
                int j = spawner(generator);
                if (state[j / 10 + 1][j % 10 + 1]) i--;
                state[j / 10 + 1][j % 10 + 1] = 1;
            }//spawn the appropriate amount of dislocations
             */
            state[(N-1)/2][(N-1)/2] = 1;
            for (int i = 0; i < N; i++) {
                state[i][0] = 2;
                state[0][i] = 2;
                state[i][N - 1] = 2;
                state[N - 1][i] = 2;
            }//sets all the borders to 2
            fix(state);//fixes the already connected dislocations

            while (step(state, distr, generator)) {
                time += 1;
            }//runs the simulation
            myfile << time << ';';
        }
        myfile <<'\n';
//}
    myfile.close();
    return 0;
}
