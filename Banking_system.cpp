#include<iostream>
using namespace std;

class BankAccount{
    private:
    double balance;
    public:
    BankAccount(double b){
        balance= b;
    }
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
    void deposit(int amount){
        balance += amount;
    }
    void withdraw(int amount){
        if(amount <= balance){
            balance -= amount;
            cout<< "Balance := "<< balance<<endl ;
        }
        else{
            cout<< "Insufficient Balance  "<< endl;
        }
    }
    double  getBalance() const{
        return balance;
    }
};
int main(){
    BankAccount* Account1= new BankAccount(0);
    Account1->deposit(100);
    Account1->withdraw(80);
    Account1->getBalance();

}