#include "matrise.h"
#include "iostream"


Matrix::Matrix(int r , int c)
{
    while(r == 0){
        std::cout<<"r can not be zero" << std::endl;
        std::cin>>r;
    }
    while(c == 0){
        std::cout<<"c can not be zero" << std::endl;
        std::cin>>c;
    }
    if(r != 0){
        rows = r;
    }
    if(c != 0){
        columns = c;
    }
    
}