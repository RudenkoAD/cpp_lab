#include <cstring>
#include <iostream>

struct student{
    char name[20];
    int grade;
};

int main(){
    student students[10];
    for (int i=0; i<10; i++){
        std::cin>>students[i].name>>students[i].grade;
    }
    int M;
    std::cin>>M;
    for (int i=0; i<10; i++){
        if (students[i].grade>=M){
            std::cout<<students[i].name<<' ';
        }
    }
}


