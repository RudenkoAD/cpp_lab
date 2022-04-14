#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack* A = new Stack;
    char ch;
    int a, b;
    cin>>ch;
    while(ch!='\n' and ch!='\0'){
        switch(ch){
            case ' ':
                break;
            case '+':
                a=A->pop();
                b=A->pop();
                A->push(a+b);
                break;
            case '-':
                a=A->pop();
                b=A->pop();
                A->push(a-b);
                break;
            case '*':
                a=A->pop();
                b=A->pop();
                A->push(a*b);
                break;
            case '/':
                a=A->pop();
                b=A->pop();
                A->push(a/b);
                break;
            default:
                try {A->push(static_cast<int>(ch-48));}
                catch(exception){
                    cout<<"WTF";
                    return -1;
                }
        }
        cin>>ch;
    }
    cout<<A->Top();
}

