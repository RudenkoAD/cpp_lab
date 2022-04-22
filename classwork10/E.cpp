#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    char *ga = new char[a+1], *gb = new char[b+1];
    cin>>ga>>gb;

    int **matrix = new int *[a + 1];
    for (int i = 0; i < a + 1; i++) {
        matrix[i] = new int[b + 1];
        for (int j = 0; j < b + 1; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i < a + 1; i++) {
        for (int j = 1; j < b + 1; j++) {
            if (ga[i - 1] == gb[j - 1]) matrix[i][j] = matrix[i-1][j-1]+1;
            else matrix[i][j] = max(matrix[i][j - 1], matrix[i-1][j]);
        }
    }
    char* ans= new char[min(a, b) + 1];
    int ans_id=0, i=a, j=b;
    while(i>0 and j>0){
            if (matrix[i][j] + matrix[i - 1][j - 1] - matrix[i - 1][j] - matrix[i][j - 1] == 1) {
                ans[ans_id] = ga[i - 1];
                ans_id++;
                i--;
                j--;
            }
            else if(matrix[i][j]==matrix[i-1][j]) i--;
            else if(matrix[i][j]==matrix[i][j-1]) j--;
    }
    ans[ans_id]='\0';
    strrev(ans);
    cout<<ans;
}