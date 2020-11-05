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
     char  ble_rx_buffer[28] = "$0xDA;12:00:02;15;12:42:01\n";

     // act
     return_val = config_parse(ble_rx_buffer);

     // assert
     LONGS_EQUAL(ZELP_SUCCESS, return_val);
     
 }

 TEST(Config, check_for_newline_at_end_of_buffer_fails)
 {
    // arrange
     uint16_t return_val = true;
    char  ble_rx_buffer[28] =  "$0xDA;12:00:02;15;12:42:01";
 

     // act
     return_val = config_parse(ble_rx_buffer);

     // assert
     LONGS_EQUAL(ZELP_BAD_RESPONSE, return_val);
     
 }

 TEST(Config, buffer_has_too_long_data)
 {
    // arrange
     uint16_t expected_value = ZELP_BAD_RESPONSE;
     char const *invalid_config_buffer = "$0xDA;12:00:02;15;12:42:01.\n";
     
      //initially set to success to allow it to be changed to opposite
     uint16_t return_val = ZELP_SUCCESS;

     // act
     return_val = config_parse((char*)invalid_config_buffer);

     // assert
     LONGS_EQUAL(expected_value, return_val);
     
 }

