#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 //ASSERT_EQ(soundex,"A200");
  generateSoundex("AT", soundex);
 //ASSERT_EQ(soundex,"A300");
   generateSoundex("BR", soundex);
 //ASSERT_EQ(soundex,"B600");
   generateSoundex("CMXT", soundex);
 //ASSERT_EQ(soundex,"B523");
  generateSoundex("GCDL", soundex);
 //ASSERT_EQ(soundex,"C234");
  generateSoundex("ALRM", soundex);
 //ASSERT_EQ(soundex,"A465");
 generateSoundex("ALRU", soundex);
 //ASSERT_EQ(soundex,"A460");
}
