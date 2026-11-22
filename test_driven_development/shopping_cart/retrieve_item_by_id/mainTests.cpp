#include "../src/main.hpp"
#include <gtest/gtest.h>

class ShoppingCartTests : public ::testing::Test {
protected:
    ShoppingCart cart;
};

// Requirement #1
TEST_F(ShoppingCartTests, ShoppingCart_ShouldStartWithAnEmptyCart) {
    EXPECT_EQ(0, cart.GetItemCount());
    EXPECT_EQ(0, cart.GetTotal());
}

// Requirement #2
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddOneItemToCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

// Requirement #3
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddMultipleItemsAndCalculateTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    cart.AddItem(ShoppingCart::Product("2", "Pen", 5));
    EXPECT_EQ(2, cart.GetItemCount());
    EXPECT_EQ(15, cart.GetTotal());
}

// Requirement #4
TEST_F(ShoppingCartTests, ShoppingCart_ShouldHandleMultipleQuantitiesOfSameItem) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 3);
    EXPECT_EQ(3, cart.GetItemCount());
    EXPECT_EQ(30, cart.GetTotal());
}

// Requirement #5
TEST_F(ShoppingCartTests, ShoppingCart_ShouldRemoveItemsFromCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.RemoveItem("1");
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

// Requirement #6
TEST_F(ShoppingCartTests, ShoppingCart_ShouldThrowError_WhenRemovingNonExistentItem) {
    EXPECT_THROW(cart.RemoveItem("999"), ShoppingCart::ItemNotFoundException);
}

// Requirement #7
TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyPercentageDiscountToTotal) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 100));
    cart.ApplyDiscount(10); // 10% discount
    EXPECT_EQ(90, cart.GetTotal());
}

// Requirement #8
TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyBulkDiscountWhenTotalExceeds150) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 200));
    EXPECT_EQ(180, cart.GetTotal());
}

// Requirement #9
TEST_F(ShoppingCartTests, ShoppingCart_ShouldClearAllItemsFromCart) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.Clear();
    EXPECT_EQ(0, cart.GetItemCount());
    EXPECT_EQ(0, cart.GetTotal());
}

// Requirement #10
TEST_F(ShoppingCartTests, ShoppingCart_ShouldUpdateItemQuantity) {
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);
    cart.UpdateQuantity("1", 3);
    EXPECT_EQ(3, cart.GetItemCount());
    EXPECT_EQ(30, cart.GetTotal());
}

// Requirement #11
TEST_F(ShoppingCartTests, ShoppingCart_ShouldNotAllowMoreThanTenOfTheSameItem) {
    EXPECT_THROW(cart.AddItem(ShoppingCart::Product("1", "Book", 10), 11), ShoppingCart::InvalidOperationException);
}


TEST_F(ShoppingCartTests, ShoppingCart_ShouldReturnItemDetailsById) 
{
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 9);
    auto result = cart.GetItem("1");
    EXPECT_EQ("1", result.Id);
    EXPECT_EQ("Book", result.Name);
    EXPECT_EQ(10, result.Price);
    EXPECT_EQ(9, result.Quantity);
    EXPECT_THROW(cart.RemoveItem("999"), ShoppingCart::ItemNotFoundException);
}

// TODO: Implement test for Requirement #12 - Retrieving Item Details by ID
// The test should:
// 1. Create a product with known ID, name, and price (e.g., "1", "Book", 10)
// 2. Add the product to the cart with a specific quantity
// 3. Retrieve the item using GetItem(id) method
// 4. Verify that all item properties match expectations:
//    - ID matches original product ID
//    - Name matches original product name
//    - Price matches original product price
//    - Quantity matches what was added to the cart
// 5. Consider also testing that GetItem throws ItemNotFoundException when ID doesn't exist