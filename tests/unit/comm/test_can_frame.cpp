#include <gtest/gtest.h>
#include "autocore/comm/CanFrame.hpp"

using namespace autocore::comm;

TEST(CanFrame, DefaultConstructor) {
    CanFrame f;
    EXPECT_EQ(f.id(), 0u);
    EXPECT_EQ(f.dlc(), 0u);
}

TEST(CanFrame, ConstructorStoresIdAndDlc) {
    uint8_t data[2] = {0x0A, 0x2B};
    CanFrame f(0x100, 2, data);
    EXPECT_EQ(f.id(), 0x100u);
    EXPECT_EQ(f.dlc(), 2u);
    EXPECT_EQ(f.data()[0], 0x0A);
    EXPECT_EQ(f.data()[1], 0x2B);
}

TEST(CanFrame, ClampsOversizedDlc) {
    uint8_t data[8] = {1,2,3,4,5,6,7,8};
    CanFrame f(0x200, 99, data);
    EXPECT_EQ(f.dlc(), 8u);
}

TEST(CanFrame, HandlesNullDataPointer) {
    CanFrame f(0x300, 4, nullptr);
    EXPECT_EQ(f.id(), 0x300u);
    EXPECT_EQ(f.dlc(), 4u);
    EXPECT_EQ(f.data()[0], 0u);
}

TEST(CanFrame, ToStringIsReadable) {
    uint8_t data[2] = {0x0A, 0x2B};
    CanFrame f(0x100, 2, data);
    EXPECT_EQ(f.toString(), "ID=0x100 DLC=2 DATA=0A 2B ");
}