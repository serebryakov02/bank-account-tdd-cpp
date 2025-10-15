#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

class BankAccount
{
    double m_balance;
    static size_t Count;
    size_t m_accountNumber;

public:
    BankAccount()
     : m_balance(0.0), m_accountNumber(0) { 
        m_accountNumber = ++Count;
    }

    double getBalance() const { return m_balance; }
    size_t getAccountNumber() const { return m_accountNumber; }
};

size_t BankAccount::Count = 0;

#endif