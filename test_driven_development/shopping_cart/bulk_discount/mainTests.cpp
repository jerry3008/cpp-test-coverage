#include "../src/main.hpp"
#include <gtest/gtest.h>

class ShoppingCartTests : public ::testing::Test {
protected:
    ShoppingCart cart;
};

TEST_F(ShoppingCartTests, ShoppingCart_ShouldStartWithAnEmptyCart) {
    EXPECT_EQ(0, cart.GetItemCount());
    EXPECT_EQ(0, cart.GetTotal());
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddOneItemToCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddMultipleItemsAndCalculateTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    cart.AddItem(ShoppingCart::Product("2", "Pen", 5));
    EXPECT_EQ(2, cart.GetItemCount());
    EXPECT_EQ(15, cart.GetTotal());
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldHandleMultipleQuantitiesOfSameItem) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 3);
    EXPECT_EQ(3, cart.GetItemCount());
    EXPECT_EQ(30, cart.GetTotal());
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldRemoveItemsFromCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.RemoveItem("1");
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldThrowError_WhenRemovingNonExistentItem) {
    EXPECT_THROW(cart.RemoveItem("999"), ShoppingCart::ItemNotFoundException);
}

TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyPercentageDiscountToTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 100));
    cart.ApplyDiscount(10); // 10% discount
    EXPECT_EQ(90, cart.GetTotal());
}


TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyaDiscount) 
{
    cart.AddItem(ShoppingCart::Product("1", "Book", 200)); // 10% discount
    EXPECT_EQ(180, cart.GetTotal());
}
