#include <gmock/gmock.h>
#include "BankAccount.h"
using testing::Eq;

TEST(BankAccount, BalanceIsZeroOnCreation) 
{
    BankAccount account;
    ASSERT_THAT(account.getBalance(), testing::Eq(0.0));
}