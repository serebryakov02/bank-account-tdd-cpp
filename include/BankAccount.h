#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

class BankAccount
{
    double m_balance;
    static const size_t Count { 0 };
    size_t m_accountNumber;

public:
    BankAccount()
     : m_balance(0.0), m_accountNumber(0) { 
        m_accountNumber = Count + 1;
    }

    double getBalance() const { return m_balance; }
    size_t getAccountNumber() const { return m_accountNumber; }
};

#endif