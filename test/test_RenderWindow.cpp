#include <iostream>

#include "gtest/gtest.h"

#include "RenderWindow.hpp"

const kn::math::Vec2 kn::SCREEN_SIZE = {100, 100};

namespace
{
using kn::RenderWindow;

class RenderWindowTest : public ::testing::Test
{
  protected:
    RenderWindowTest()
    {
        // Have to set this before first test
        if (!RenderWindow::setScale(2))
        {
            std::cout << "setScale failed in RenderWindowTest constructor\n";
        }
    }

    virtual ~RenderWindowTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}
};

TEST_F(RenderWindowTest, SingletonPointersEqual)
{
    const RenderWindow* window1 = &RenderWindow::getInstance();
    const RenderWindow* window2 = &RenderWindow::getInstance();

    EXPECT_EQ(window1, window2);
}
}