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
    char const *ble_rx_buffer = "abc\n";
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
     LONGS_EQUAL(ZELP_BAD_RESPONSE, return_val);
 }

 TEST(Config, check_for_newline_at_end_of_buffer_passes)
 {
    // arrange
     uint16_t return_val = false;
     char  ble_rx_buffer[5] = {'t','\n'};

     // act
     return_val = config_parse(ble_rx_buffer);

     // assert
     LONGS_EQUAL(ZELP_SUCCESS, return_val);
     
 }

 TEST(Config, check_for_newline_at_end_of_buffer_fails)
 {
    // arrange
     uint16_t return_val = true;
     char  ble_rx_buffer[5] = {'t'};
     

     // act
     return_val = config_parse(ble_rx_buffer);

     // assert
     LONGS_EQUAL(ZELP_BAD_RESPONSE, return_val);
     
 }
