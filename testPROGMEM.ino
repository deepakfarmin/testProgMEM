 
 /*
 *  Author: Deepak Reddy
 *  Version : v1.0
 *  Edited on : 03/18/2018
 */

#include "PROGMEM_readAnything_.h"

const uint8_t NUMBER_OF_ELEMENTS = 216;

 // Creating lookup table using ProgMEM
  const PROGMEM uint8_t PwmDutyCycle[]  {
 // 0   1    2   3     4    5    6    7    8   9    10   11   12   13   14   
  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,    // 1
  55,  56,  57,  58,  59,  60,  61,  62,  64,  65,  66,  63,  67,  68,  69,    // 2
  70,  71,  72,  73,  74,  75,  76,  78,  77,  79,  80,  81,  82,  83,  84,    // 3
  85,  86,  89,  87,  90,  88,  91,  92,  93,  94,  95,  96,  97,  98,  99,    // 4
  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,   // 5
  115, 116, 117, 118, 119, 120, 121, 123, 122, 124, 125, 126, 127, 128, 129,   // 6
  130, 131, 133, 134, 132, 135, 136, 137, 138, 139, 140, 141, 142, 145, 143,   // 7
  144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,   // 8
  160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174,   // 9 
  175, 177, 179, 178, 176, 180, 181, 182, 183, 184, 185, 186, 187, 188, 191,   // 10
  189, 190, 192, 193, 194, 195, 196, 199, 197, 198, 200, 202, 201, 203, 205,   // 11
  206, 204, 207, 208, 209, 211, 210, 212, 213, 214, 215, 216, 217, 218, 219,   // 12 
  220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234,   // 13
  235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249,   // 14 
  250, 251, 252, 253, 254, 255                                                 // 15
  };


  const PROGMEM int DeltaPulse[]  {
 // 0    1     2     3     4     5     6     7     8     9    10    11    12    13    14        
  393,  407,  425,  456,  468,  488,  514,  533,  559,  593,  629,  650,  682,  699,  723,     // 1
  755,  760,  807,  837,  891,  902,  916,  939,  977,  990,  995,  999,  1027, 1066, 1071,    // 2
  1085, 1097, 1132, 1164, 1175, 1207, 1278, 1337, 1343, 1352, 1380, 1408, 1434, 1442, 1466,    // 3
  1497, 1521, 1552, 1553, 1578, 1586, 1594, 1620, 1643, 1668, 1709, 1727, 1764, 1789, 1798,    // 4
  1829, 1869, 1894, 1916, 1917, 1949, 1954, 1976, 1998, 2015, 2031, 2054, 2086, 2113, 2131,   // 5
  2161, 2173, 2213, 2234, 2244, 2271, 2312, 2339, 2351, 2371, 2384, 2412, 2433, 2444, 2459,    // 6
  2496, 2550, 2554, 2558, 2562, 2586, 2614, 2641, 2672, 2694, 2724, 2767, 2799, 2820, 2823,   // 7
  2825, 2851, 2867, 2899, 2903, 2958, 2977, 3016, 3051, 3148, 3171, 3191, 3221, 3240, 3255,   // 8
  3284, 3294, 3305, 3326, 3334, 3353, 3363, 3398, 3430, 3452, 3480, 3485, 3493, 3512, 3575,    // 9
  3601, 3640, 3642, 3644, 3646, 3691, 3704, 3712, 3732, 3738, 3760, 3767, 3812, 3891, 3922,    // 10
  3929, 3933, 3938, 3972, 3997, 4061, 4062, 4115, 4134, 4135, 4170, 4186, 4196, 4214, 4262,   // 11 
  4281, 4294, 4299, 4320, 4339, 4403, 4421, 4451, 4488, 4518, 4555, 4577, 4581, 4620, 4683,    // 12
  4684, 4687, 4708, 4727, 4760, 4825, 4834, 4842, 4865, 4894, 4901, 4922, 4931, 4943, 4966,   // 13
  4979, 4995, 5098, 5113, 5114, 5120, 5133, 5212, 5234, 5291, 5298, 5325, 5351, 5363, 5363,  // 14
  5397, 5449, 5492, 5527, 5537, 5550   // 15  
};



 
void setup() 
{
   Serial.begin(115200);

 
    // while (! Serial);
 // Serial.println("Enter Pulsepersec");

}

void loop() 
{

 // if (Serial.available())
  
    int startmillis = millis();   
     unsigned long startmicros = micros();         
    float DesiredPPS = 54.8;
    int DesiredPPM = DPPS*60;
   int RefPPM;
   PROGMEM_readAnything(&DeltaPulse[107], RefPPM);
  // int RPS = RefPulsePerMin/60;
   
   if(RefPPM > DesiredPPM)  
   {
    uint8_t k;
    uint8_t kdx = 0; // default index of first element
    int DeltaPulsePerMin;
    PROGMEM_readAnything(&DeltaPulse[kdx], DeltaPulsePerMin);
    float InitialPulsePerSec = (float) DeltaPulsePerMin/60.0;
    float InitialDifference = abs(InitialPulsePerSec - DesiredPulse);
  for (size_t k = 1; k < 107; k++)
  {
    //       Serial.print("\n");
//       Serial.print(k);
    int DeltaPulsePerMin;
    PROGMEM_readAnything(&DeltaPulse[k], DeltaPulsePerMin);
    float NextPulsePerSec = (float) DeltaPulsePerMin/60.0 ;

       Serial.print("\n");
       Serial.print("NP");
       Serial.print("\t");
      Serial.print(NextPulsePerSec);
      Serial.print("\n");
       Serial.print("ID");
       Serial.print("\t");
      Serial.print(InitialDifference);

      float FinalDifference = abs(NextPulsePerSec - DesiredPulse);
      Serial.print("\n");
       Serial.print("FD");
      Serial.print("\t");
      Serial.print(FinalDifference);
      //delay(50);
      if (FinalDifference >= InitialDifference)
      {
        
        kdx = k-1;
        break;
      }
     InitialDifference = FinalDifference;
     Serial.print("\n");
     Serial.print("Index");
     Serial.print("\t");
     Serial.print(k);
   }
   Serial.print("\n");
   Serial.print("PWM Index");
   Serial.print("\t");
   Serial.print(kdx);
   uint8_t GetPWM;
   PROGMEM_readAnything(&PwmDutyCycle[kdx], GetPWM);
   Serial.print("\n");
   Serial.print("PWM");
   Serial.print("\t");
   Serial.print(GetPWM);
   }
   else
   {
    uint8_t k;
    uint8_t kdx = 108; // default index of first element
    int DeltaPulsePerMin;
    PROGMEM_readAnything(&DeltaPulse[kdx], DeltaPulsePerMin);
    float InitialPulsePerSec = (float) DeltaPulsePerMin/60.0;
    float InitialDifference = abs(InitialPulsePerSec - DesiredPulse);
  for (size_t k = 109; k < NUMBER_OF_ELEMENTS; k++)
  {
    //       Serial.print("\n");
//       Serial.print(k);
    int DeltaPulsePerMin;
    PROGMEM_readAnything(&DeltaPulse[k], DeltaPulsePerMin);
    float NextPulsePerSec = (float) DeltaPulsePerMin/60.0 ;

       Serial.print("\n");
       Serial.print("NP");
       Serial.print("\t");
      Serial.print(NextPulsePerSec);
      Serial.print("\n");
       Serial.print("ID");
       Serial.print("\t");
      Serial.print(InitialDifference);

      float FinalDifference = abs(NextPulsePerSec - DesiredPulse);
      Serial.print("\n");
       Serial.print("FD");
      Serial.print("\t");
      Serial.print(FinalDifference);
      //delay(50);
      if (FinalDifference >= InitialDifference)
      {
        
        kdx = k-1;
        break;
      }
     InitialDifference = FinalDifference;
     Serial.print("\n");
     Serial.print("Index");
     Serial.print("\t");
     Serial.print(k);
   }
   Serial.print("\n");
   Serial.print("PWM Index");
   Serial.print("\t");
   Serial.print(kdx);
   uint8_t GetPWM;
   PROGMEM_readAnything(&PwmDutyCycle[kdx], GetPWM);
   Serial.print("\n");
   Serial.print("PWM");
   Serial.print("\t");
   Serial.print(GetPWM);
   }
   
   int calcperiod = millis() - startmillis;
   unsigned long calcperiod_micros = micros() - startmicros;
  Serial.print("\n");
   Serial.print("Period");
   Serial.print("\t");
   Serial.print(calcperiod);
     Serial.print("\n");
   Serial.print("Period micros");
   Serial.print("\t");
   Serial.print(calcperiod_micros);
   delay(5000);
  
}

  


