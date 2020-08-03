
    
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  CallYourAPI(Data, Size); // TODO call your API here
  return 0;  // Non-zero return values are reserved for future use.
}
