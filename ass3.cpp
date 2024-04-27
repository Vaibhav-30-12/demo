#include<iostream>
#include<string>
using namespace std;

class wallet{
    private:
    double balance;// balance available in account
    friend class admin;
    static int count;//keep track of the coubt of wallets





    public:

    int id;//the count number is assigned
    wallet(){
        id= count +1;
        balance =0.00;
    }
    wallet(double initial_balance){
        balance=initial_balance;
        id= count +1;


    }
    wallet(wallet &w){
       id= count+1;
       balance=w.balance;
    }   
     double getbalance(){
        return balance;

        }
        // fetches the balance in the account
    double topup(double  amount){
        balance =amount +balance;
        return balance;

        }
        //adds to the account balance
    bool sendmoney(wallet * ,double);



};

int wallet::count =0;
class admin{
    public:
    bool mediatetransfer(wallet *from_wallet, wallet *to_w,double amount){
        if(from_wallet->balance>=amount){
            from_wallet->balance=from_wallet->balance-amount;
            to_w->balance+=amount;
            return true;
}
        else{
            cout<<"insufficient fund !!!!";
            return false;
        }


        }

    }
;
bool wallet::sendmoney(wallet *w ,double amount){
        admin mediator;
        return mediator.mediatetransfer(this, w,amount);
}
int main(){
    wallet *w1 = new wallet(1000.00);
    wallet *w2 =new wallet(1000.00);
    wallet *w3 = new wallet(0.00);
    admin a;
    cout << "Initial balance in w1: " << w1->getbalance() << endl;
    cout << "Initial balance in w2: " << w2->getbalance() << endl;

    a.mediatetransfer(w1, w2, 200.00); // Transfer from w1 to w2
//w1->sendmoney(w2,100);
    cout << "Balance in w1 after transfer: " << w1->getbalance() << endl;
    cout << "Balance in w2 after transfer: " << w2->getbalance() << endl;

    delete w1;
    delete w2;
    delete w3;

    return 0;



}