#include <iostream>

struct timer{
    int H;
    int M;
    int S;
    timer(int tH, int tM, int tS){
        H=tH;
        M=tM;
        S=tS;
    }
    timer operator+(timer t){
        int tH=H+t.H;
        int tM=M+t.M;
        int tS=S+t.S;
        tM+=tS/60;
        tS=tS%60;
        tH+=tM/60;
        tM=tM%60;
        tH%=24;
        return timer(tH, tM, tS);
    }
};

void print(timer a){
    std::cout<<a.H<<':'<<a.M<<':'<<a.S<<'\n';
}

int main(){
    int a, b, c, d, e, f;
    std::cin>>a>>b>>c>>d>>e>>f;
    timer t1 = timer(a, b, c);
    timer t2 = timer(d, e, f);
    print(t1+t2);
}
