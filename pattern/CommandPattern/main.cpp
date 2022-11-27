#include <iostream>

class BankAccount
{
public:
    BankAccount(int balance = 0) : mBalance(balance)
    {}
    void deposit(const int amount)
    {
        mBalance += amount;
        std::cout << "deposited: " << amount << std::endl;
    }
    bool withDraw(const int amount)
    {
        if (mBalance - amount >= mOverDraft_limit)
        {
            mBalance -= amount;
            std::cout << "withdraw amount: " << amount << "and Balance is: " << mBalance << std::endl;
            return true;
        }
        return false;
    }
private:
    int mBalance = 0;
    int mOverDraft_limit = -500;
};

class Command
{
public:
    Command() {}
    virtual void call() = 0;
    virtual void undo() = 0;
};

class BankAccountCommand : public Command
{
public:
    enum Action {deposit,withdraw} action;
    BankAccountCommand(BankAccount bankAccount,const Action action,const int amount) : Command()
    {
        this->action  = action;
        this->amount  = amount;
        account = bankAccount;
        withdrawal_succeeded = false;
    }
    void setAmount(const int amount)
    {
        this->amount = amount;
    }

    void call() override
    {
        switch(this->action)
        {
            case deposit:
                account.deposit(amount);
                break;
            case withdraw:
                withdrawal_succeeded = account.withDraw(amount);
                break;
        }
    }
    void undo () override
    {
        switch (action)
        {
            case withdraw:
                if(withdrawal_succeeded)
                    account.deposit(amount);
                break;
            case deposit:
                account.withDraw(amount);
                break;
        }
    }
private:
    BankAccount account;
    int amount;
    bool withdrawal_succeeded;
};

int main()
{
   BankAccount ba;
   BankAccountCommand Bacmd(ba,BankAccountCommand::deposit,100);
   Bacmd.call();

   Bacmd.action = BankAccountCommand::withdraw;
   Bacmd.setAmount(50);

   Bacmd.call();
   return 0;
}
