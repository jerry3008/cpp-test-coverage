#include <gtest/gtest.h>
#include "../src/UserManager.hpp"

// TODO: add a test for 'AddUser_AddsValidUser'
//       - create a new UserManager();
//       - call userManager.AddUser() to add 'john'
//       - verify that userManager.GetUsers() contains 'john'

TEST(UserManagerTests, AddUser_AddsValidUser)
{
    UserManager userManager;
    userManager.AddUser("john");
    auto result = userManager.GetUsers();
    EXPECT_NE(std::find(result.begin(), result.end(), "john"), result.end());
}