#ifndef PlungingProbeArtRecord_hh
#define PlungingProbeArtRecord_hh

//==============================================================================
// File:   PlungingProbeArtRecord.hh
// Author: David Flay 
// Email:  flay@umass.edu
// About:  Defines art data products to represent 
//         the absolute calibration probe measurements 
//==============================================================================

#define G2FIELD_PLUNGING_PROBE_NPOS 17 
#define G2FIELD_PLUNGING_PROBE_FID_LEN 1000000

namespace gm2field {

   struct PlungingProbeArtRecord { 
      unsigned long int sys_clock;   // system clock 
      unsigned long int gps_clock;   // GPS clock 
      uint16_t health;               // status indicator of probe 
      uint16_t method;               // chosen method for frequency extraction 
      double x;                      // Cartesian coordinate x [plunging probe coordinate system] 
      double y;                      // Cartesian coordinate y [plunging probe coordinate system] 
      double z;                      // Cartesian coordinate z [plunging probe coordinate system] 
      double temperature;            // temperature in Celsius  
      double freq;                   // frequency in Hz             
      double freq_err;               // frequency uncertainty in Hz 
      double freq_zc;                // frequency in Hz [zero crossing]      
      double freq_zc_err;            // frequency uncertainty in Hz [zero crossing] 

      // default constructor 
      PlungingProbeArtRecord() : 
	sys_clock(0), 
	gps_clock(0), 
        health(0x0000), 
        method(0x0000), 
        x(0),
        y(0),
        z(0),
        temperature(0),
        freq(0),
        freq_err(0),
        freq_zc(0),
        freq_zc_err(0) {} 

   }; // end of PlungingProbeArtRecord  

   // data product that keeps traces 
   struct PlungingProbeFidArtRecord : public PlungingProbeArtRecord { 
      std::vector<std::vector<uint16_t>> trace;
#ifndef __ROOTCLING__
      PlungingProbeFidArtRecord() : 
	 trace(G2FIELD_PLUNGING_PROBE_NPOS,
	       std::vector<uint16_t>(G2FIELD_PLUNGING_PROBE_FID_LEN,0)) {} 
#endif  
   }; 

   // typedefs 
   typedef std::vector<PlungingProbeArtRecord> PlungingProbeArtRecordCollecton; 
   typedef std::vector<PlungingProbeFidArtRecord> PlungingProbeFidArtCollection; 


} // ::gm2field 

#endif 
