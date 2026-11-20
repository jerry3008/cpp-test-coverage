#include <gtest/gtest.h>
#include "../src/main.hpp"

class ShoppingCartTests : public ::testing::Test {
protected:
    ShoppingCart cart; // Cart instance available to all tests
    
    void SetUp() override {
        // Setup code runs before each test
        // A fresh cart instance is created for each test
    }
};

// Requirement #1
TEST_F(ShoppingCartTests, ShoppingCart_ShouldStartWithAnEmptyCart) {
    // Act
    int itemCount = cart.getItemCount();
    double total = cart.getTotal();

    // Assert
    EXPECT_EQ(0, itemCount);
    EXPECT_EQ(0.0, total);
}

// Requirement #2
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddOneItemToCart) {
    // Act
    cart.addItem(ShoppingCart::Product{"1", "Book", 10.0});

    // Assert
    EXPECT_EQ(1, cart.getItemCount());
    EXPECT_EQ(10.0, cart.getTotal());
}

// Requirement #3
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddMultipleItemsAndCalculateTotal) {
    // Act
    cart.addItem(ShoppingCart::Product{"1", "Book", 10.0});
    cart.addItem(ShoppingCart::Product{"2", "Pen", 5.0});

    // Assert
    EXPECT_EQ(2, cart.getItemCount());
    EXPECT_EQ(15.0, cart.getTotal());
}

// Requirement #4
TEST_F(ShoppingCartTests, ShoppingCart_ShouldHandleMultipleQuantitiesOfSameItem) {
    // Act
    cart.addItem(ShoppingCart::Product{"1", "Book", 10.0}, 3);

    // Assert
    EXPECT_EQ(3, cart.getItemCount());
    EXPECT_EQ(30.0, cart.getTotal());
}



TEST_F(ShoppingCartTests, ShoppingCart_ShouldRemoveItemFromCart) {
    // Act
    cart.addItem(ShoppingCart::Product{"1", "Book", 10.0}, 2);
    cart.removeItem("1");
    // Assert
    EXPECT_EQ(1, cart.getItemCount());
    EXPECT_EQ(10.0, cart.getTotal());
}

// TODO: Add a test for Requirement #5 - Removing an Item
// - The test should be named ShoppingCart_ShouldRemoveItemFromCart
// - In the Arrange section: Add a Book with id "1", price 10.0, and quantity 2
// - In the Act section: Call removeItem("1") to remove one book
// - In the Assert section: 
//   - Check that getItemCount() returns 1 (one book remaining)
//   - Check that getTotal() returns 10.0 (price of one book)