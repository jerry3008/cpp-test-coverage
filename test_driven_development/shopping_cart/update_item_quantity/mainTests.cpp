#include <gtest/gtest.h>
#include "../src/main.hpp"

class ShoppingCartTests : public ::testing::Test {
protected:
    ShoppingCart cart;

    ShoppingCartTests() {
        // Arrange
    }
};

// Requirement #1
TEST_F(ShoppingCartTests, ShoppingCart_ShouldStartWithAnEmptyCart) {
    // Act
    int itemCount = cart.GetItemCount();
    double total = cart.GetTotal();

    // Assert
    EXPECT_EQ(0, itemCount);
    EXPECT_EQ(0, total);
}

// Requirement #2
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddOneItemToCart) {
    // Act
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));

    // Assert
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

// Requirement #3
TEST_F(ShoppingCartTests, ShoppingCart_ShouldAddMultipleItemsAndCalculateTotal) {
    // Act
    cart.AddItem(ShoppingCart::Product("1", "Book", 10));
    cart.AddItem(ShoppingCart::Product("2", "Pen", 5));

    // Assert
    EXPECT_EQ(2, cart.GetItemCount());
    EXPECT_EQ(15, cart.GetTotal());
}

// Requirement #4
TEST_F(ShoppingCartTests, ShoppingCart_ShouldHandleMultipleQuantitiesOfSameItem) {
    // Act
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 3);

    // Assert
    EXPECT_EQ(3, cart.GetItemCount());
    EXPECT_EQ(30, cart.GetTotal());
}

// Requirement #5
TEST_F(ShoppingCartTests, ShoppingCart_ShouldRemoveItemsFromCart) {
    // Arrange
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);

    // Act
    cart.RemoveItem("1");

    // Assert
    EXPECT_EQ(1, cart.GetItemCount());
    EXPECT_EQ(10, cart.GetTotal());
}

// Requirement #6
TEST_F(ShoppingCartTests, ShoppingCart_ShouldThrowError_WhenRemovingNonExistentItem) {
    // Act & Assert
    EXPECT_THROW(cart.RemoveItem("999"), ShoppingCart::ItemNotFoundException);
}

// Requirement #7
TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyPercentageDiscountToTotal) {
    // Arrange
    cart.AddItem(ShoppingCart::Product("1", "Book", 100));

    // Act
    cart.ApplyDiscount(10); // 10% discount

    // Assert
    EXPECT_EQ(90, cart.GetTotal());
}

// Requirement #8
TEST_F(ShoppingCartTests, ShoppingCart_ShouldApplyBulkDiscountWhenTotalExceeds150) {
    // Act
    cart.AddItem(ShoppingCart::Product("1", "Book", 200));

    // Assert
    EXPECT_EQ(180, cart.GetTotal());
}

// Requirement #9
TEST_F(ShoppingCartTests, ShoppingCart_ShouldClearAllItemsFromCart) {
    // Arrange
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);

    // Act
    cart.Clear();

    // Assert
    EXPECT_EQ(0, cart.GetItemCount());
    EXPECT_EQ(0, cart.GetTotal());
}


TEST_F(ShoppingCartTests, ShoppingCart_ShouldUpdateItemQuantity) {
    // Arrange
    cart.AddItem(ShoppingCart::Product("1", "Book", 10), 2);

    // Act
    cart.UpdateQuantity("1", 3);

    // Assert
    EXPECT_EQ(3, cart.GetItemCount());
    EXPECT_EQ(30, cart.GetTotal());
}

