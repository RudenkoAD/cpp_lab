#include <iostream>
using namespace std;

enum Status {
    Stop=0,
    Continue=100,
    OK=200,
    Created=201,
    Accepted=202,
    Bad_Request=400,
    Unauthorized=401,
    Not_Found=404,
    Method_Not_Allowed=405,
    Internal_Server_Error=500,
    Not_Implemented=501,
    Bad_Gateway=502,
};

int main(){
    int a;
    while(cin>>a){
        switch (a) {
            case Status::Stop:
                return 0;
            case Status::Continue:
                std::cout << "Continue\n";
                break;
            case Status::OK:
                std::cout << "OK\n";
                break;
            case Status::Created:
                std::cout << "Created\n";
                break;
            case Status::Accepted:
                std::cout << "Accepted\n";
                break;
            case Status::Bad_Request:
                std::cout << "Bad Request\n";
                break;
            case Status::Unauthorized:
                std::cout << "Unauthorized\n";
                break;
            case Status::Not_Found:
                std::cout << "Not Found\n";
                break;
            case Status::Method_Not_Allowed:
                std::cout << "Method Not Allowed\n";
                break;
            case Status::Internal_Server_Error:
                std::cout << "Internal Server Error\n";
                break;
            case Status::Not_Implemented:
                std::cout << "Not Implemented\n";
                break;
            case Status::Bad_Gateway:
                std::cout << "Bad Gateway\n";
                break;
            default:
                std::cout << "Error Code Not Found\n";
                break;
        }
    }
}

