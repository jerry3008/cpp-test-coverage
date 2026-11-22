#include "../src/main.hpp"
#include <gtest/gtest.h>

class ShoppingCartTest : public ::testing::Test {
protected:
    ShoppingCart cart;
};

// Requirement #1
TEST_F(ShoppingCartTest, ShoppingCart_ShouldStartWithAnEmptyCart) {
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotal(), 0);
}

// Requirement #2
TEST_F(ShoppingCartTest, ShoppingCart_ShouldAddOneItemToCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotal(), 10);
}

// Requirement #3
TEST_F(ShoppingCartTest, ShoppingCart_ShouldAddMultipleItemsAndCalculateTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    cart.AddItem(ShoppingCart::Product("2", "Pen", 5));
    EXPECT_EQ(cart.GetItemCount(), 2);
    EXPECT_EQ(cart.GetTotal(), 15);
}

// Requirement #4
TEST_F(ShoppingCartTest, ShoppingCart_ShouldHandleMultipleQuantitiesOfSameItem) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 3);
    EXPECT_EQ(cart.GetItemCount(), 3);
    EXPECT_EQ(cart.GetTotal(), 30);
}

// Requirement #5
TEST_F(ShoppingCartTest, ShoppingCart_ShouldRemoveItemsFromCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.RemoveItem("1");
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotal(), 10);
}

// Requirement #6
TEST_F(ShoppingCartTest, ShoppingCart_ShouldThrowError_WhenRemovingNonExistentItem) {
    EXPECT_THROW(cart.RemoveItem("999"), ShoppingCart::ItemNotFoundException);
}

// Requirement #7
TEST_F(ShoppingCartTest, ShoppingCart_ShouldApplyPercentageDiscountToTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 100));
    cart.ApplyDiscount(10); // 10% discount
    EXPECT_EQ(cart.GetTotal(), 90);
}

// Requirement #8
TEST_F(ShoppingCartTest, ShoppingCart_ShouldApplyBulkDiscountWhenTotalExceeds150) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 200));
    EXPECT_EQ(cart.GetTotal(), 180);
}

// Requirement #9
TEST_F(ShoppingCartTest, ShoppingCart_ShouldClearAllItemsFromCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.Clear();
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotal(), 0);
}

// Requirement #10
TEST_F(ShoppingCartTest, ShoppingCart_ShouldUpdateItemQuantity) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.UpdateQuantity("1", 3);
    EXPECT_EQ(cart.GetItemCount(), 3);
    EXPECT_EQ(cart.GetTotal(), 30);
}

TEST_F(ShoppingCartTest, ShoppingCart_ShouldNotAllowMoreThanTenOfTheSameItem) {
   
    EXPECT_THROW( cart.AddItem(ShoppingCart::Product("1", "Book", 10), 11), ShoppingCart::InvalidOperationException);
    
}

