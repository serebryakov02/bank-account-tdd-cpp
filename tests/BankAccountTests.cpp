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

TEST_F(BankAccountTest, AccountNumberIsAssigned) 
{
    ASSERT_THAT(account.getAccountNumber(), Eq(1));
}