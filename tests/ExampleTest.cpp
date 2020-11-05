#include "CppUTest/TestHarness.h"

extern "C"
{
#include "Example.h"
}

TEST_GROUP(Config)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Config, check_parser_returns_success)
{
     // arrange
    uint16_t return_val = false;
    
    // act
    return_val = config_parse();
    // assert
    LONGS_EQUAL(1, return_val);
}

// TEST(Config, check_buffer_passed)
// {
//     // arrange
//     uint16_t return_val = false;

//     // act
//     return_val = config_parse(&buffer)
//     // assert
//     LONGS_EQUAL(1, config_parse(&buffer));
// }