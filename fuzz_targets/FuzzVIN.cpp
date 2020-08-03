#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cstdint>
#include <iostream>
#include "common.h"
#include "gs1.h"

int ZBarcode_Buffer(struct zint_symbol *symbol, int rotate_angle);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  if (Size < 4)
    return 0;

  // Add Setup code here.
  struct zint_symbol *my_symbol;my_symbol = ZBarcode_Create();
  if(my_symbol == NULL) {
    printf("Symbol creation failed!\n");
    return 1;
  }

  my_symbol->symbology = BARCODE_VIN;
  unsigned char * input = (unsigned char *) Data;
  ZBarcode_Encode_and_Buffer(my_symbol, input, Size , 0);
  // Add Teardown code here.

  ZBarcode_Delete(my_symbol);

  return 0;
}
