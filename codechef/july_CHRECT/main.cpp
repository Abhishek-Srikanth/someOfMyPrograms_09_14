#include <iostream>

int main()
{
    unsigned int T;
    unsigned int N,M,K;
    std::cin >> T;
    while(T>0)
    {
        std::cin >> N >> M >> K;
        if(N>1 && M>1)
        {
            if(K%2!=0)
                ++K;
            K/=2;
            std::cout << K << "\n";
        }
        else if((N*M)<=2)
            std::cout << "0\n";
        else if(N==1 || M==1)
            std::cout << K << "\n";

        --T;
    }
    return 0;
}
