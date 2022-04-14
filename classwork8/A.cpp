#include <iostream>
#include <cstring>

struct Snode{
    char field[20];
    Snode* next;
    Snode(char* name){
        std::strcpy(field, name);
        next=nullptr;
    }
};

struct Loop{
    Snode* first=nullptr;
    Snode* last=nullptr;
    Snode* cur=nullptr;

    void Append(char* field){
        Snode* app = new Snode(field);
        if(last!=nullptr) last->next=app;
        else first=app;
        last=app;
    }

    void Finish(){
        last->next=first;
        cur=last;
    }

    void Kill(){
        cur->next = cur->next->next;
        delete cur->next;
    }

    void Step(){
        cur = cur->next;
    }

    Snode* Play(int M){
        while(cur->next!=cur) {
            for (int i = 0; i < M-1; i++) {
                Step();
            }
            Kill();
        }
        return cur;
    }
};

int main(){
    int N;
    char name[20];
    Loop A;
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>name;
        A.Append(name);
    }
    A.Finish();
    std::cin>>N;
    std::cout<<A.Play(N)->field;
}


