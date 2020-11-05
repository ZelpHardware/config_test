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

TEST(Config, check_parser_supplied_string_returns_success)
{
     // arrange
    char const *ble_rx_buffer = "abc";
    // act +  assert
    LONGS_EQUAL(ZELP_SUCCESS, config_parse((char*)ble_rx_buffer));
}

 TEST(Config, check_buffer_returns_error_for_empty_string)
 {
     // arrange
     uint16_t return_val = false;
     char  ble_rx_buffer[5] = {'\0'};

     // act
     return_val = config_parse(ble_rx_buffer);

     // assert
     LONGS_EQUAL(ZELP_FAIL, return_val);
 }

 TEST(Config, check_for_newline_at_end_of_buffer)
 {
     //arrange
 }