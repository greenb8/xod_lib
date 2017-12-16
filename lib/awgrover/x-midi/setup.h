// Common stuff when using MIDI. Have to paste it into each patch.cpp

{{#global}}
#include <MIDI.h>
namespace xod {
namespace awgrover__x_midi {
  #ifndef MIDI47_DEFAULT_INSTANCE
    // create one 'MIDI' object only once
    #define MIDI47_DEFAULT_INSTANCE
    bool MIDI_DefaultInited=0; // control setup once

    MIDI_CREATE_DEFAULT_INSTANCE(); // MIDI

    void midi_setup() {
      // this should be in setup
      // ( call as xod::awgrover__x_midi::midi_setup(); in evaluate)
      if (!MIDI_DefaultInited) {
        // this will reset the serial port to 31250 (or settings BaudRate) for the midi's serial port
        MIDI.begin(MIDI_CHANNEL_OMNI); // Enable Soft Thru, everything at the input is sent back
        DEBUG_SERIAL.print(millis());DEBUG_SERIAL.print(F(" MIDI.begin()")); // at midi baud rate
        MIDI_DefaultInited = 1;
      }
    }
  #endif
}}
{{/global}}
