#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

class BankAccount
{
    double m_balance;

public:
    BankAccount() : m_balance(0.0) {}

    double getBalance() const { return m_balance; }
};

#endif