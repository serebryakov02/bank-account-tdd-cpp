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

TEST_F(BankAccountTest, DepositDoesNotChangeBalanceWhenAmountIsNegative)
{
    double deposit = -150.0;
    account.deposit(deposit);
    ASSERT_THAT(account.getBalance(), Eq(0.0));
}

TEST_F(BankAccountTest, DepositDoesNotChangeBalanceWhenAmountIsZero)
{
    double deposit = 0.0;
    account.deposit(deposit);
    ASSERT_THAT(account.getBalance(), Eq(0.0));
}

TEST_F(BankAccountTest, DepositIncreasesBalance)
{
    double deposit = 150.0;
    account.deposit(deposit);
    ASSERT_THAT(account.getBalance(), Eq(deposit));
}

TEST_F(BankAccountTest, DepositMultipleTimesIncreasesBalance)
{
    double deposit1 = 150.0;
    double deposit2 = 350.0;
    account.deposit(deposit1);
    account.deposit(deposit2);
    ASSERT_THAT(account.getBalance(), Eq(deposit1 + deposit2));
}

TEST_F(BankAccountTest, DepositMultipleTimesIncludingNegativeAndZeroIncreasesBalance)
{
    double deposit1 = 150.0;
    double deposit2 = -50.0;
    double deposit3 = 0.0;
    double deposit4 = 350.0;
    account.deposit(deposit1);
    account.deposit(deposit2);
    account.deposit(deposit3);
    account.deposit(deposit4);
    ASSERT_THAT(account.getBalance(), Eq(deposit1 + deposit4));
}

TEST_F(BankAccountTest, WithdrawZeroDoesNotChangeBalance)
{
    double deposit = 150.0;
    account.deposit(deposit);
    double withdraw = 0.0;
    account.withdraw(withdraw);
    ASSERT_THAT(account.getBalance(), Eq(deposit));
}

TEST_F(BankAccountTest, WithdrawNegativeDoesNotChangeBalance)
{
    double deposit = 150.0;
    account.deposit(deposit);
    double withdraw = -50.0;
    account.withdraw(withdraw);
    ASSERT_THAT(account.getBalance(), Eq(deposit));
}

TEST_F(BankAccountTest, WithdrawMoreThanBalanceDoesNotChangeBalance)
{
    double deposit = 150.0;
    account.deposit(deposit);
    double withdraw = 250.0;
    account.withdraw(withdraw);
    ASSERT_THAT(account.getBalance(), Eq(deposit));
}

TEST_F(BankAccountTest, WithdrawLessThanBalanceDecreasesBalance)
{
    double deposit = 150.0;
    account.deposit(deposit);
    double withdraw = 50.0;
    account.withdraw(withdraw);
    ASSERT_THAT(account.getBalance(), Eq(deposit - withdraw));
}

TEST_F(BankAccountTest, WithdrawAllBalanceLeavesZero)
{
    double deposit = 150.0;
    account.deposit(deposit);
    double withdraw = 150.0;
    account.withdraw(withdraw);
    ASSERT_THAT(account.getBalance(), Eq(0.0));
}

TEST_F(BankAccountTest, PrintInfoPrintsAccountInfo)
{
    testing::internal::CaptureStdout(); // Redirect std::cout to gtest's capture buffer.
    account.deposit(250.0);
    account.printInfo();
    std::string output = testing::internal::GetCapturedStdout(); // Retrieve the captured stdout contents.

    std::string expected =
          "+-------------------------+\n"
          "Account #1\n"
          "Balance: 250\n"
          "+-------------------------+\n";

    ASSERT_THAT(output, Eq(expected));
}
