#include <gmock/gmock.h>
#include "BankAccount.h"
using testing::Eq;

// It is a bad practice to use 'Test' in the name of the test fixture class,
// but I am really lacking creativity today. Do not forget to change it.
class BankAccountTest : public testing::Test 
{
public:
    BankAccount account;
};

TEST_F(BankAccountTest, BalanceIsZeroOnCreation) 
{
    ASSERT_THAT(account.getBalance(), testing::Eq(0.0));
}

TEST_F(BankAccountTest, UniqueAccountNumberIsAssignedWhenCreated) 
{
    ASSERT_THAT(account.getAccountNumber(), Eq(1));

    // As a good practice it is reccomended to have only one assert
    // per test, but to avoid creating basically the same one again,
    // I will make an excpetion and add two more here.
    BankAccount account2;
    ASSERT_THAT(account2.getAccountNumber(), Eq(2));
    BankAccount account3;
    ASSERT_THAT(account3.getAccountNumber(), Eq(3));
}
