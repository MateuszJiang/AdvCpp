#include "Brass.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<accountBase>> clients;
    
    std::unique_ptr<accountBase> clientOne = std::make_unique<Brass>("Mark Zuckenberg", 381234, 12000.00);
    std::unique_ptr<accountBase> premiumClientOne = std::make_unique<BrassPlus>("Adam Sandler", 345213, 12300.00);


    clients.push_back(std::move(clientOne));
    clients.push_back(std::move(premiumClientOne));

    for(auto& i : clients)
        i->ViewAccount();


    clients[0]->Deposit(3300);
    clients[1]->Withdraw(13000.00);
    clients[0]->ViewAccount();
    clients[1]->ViewAccount();
}
