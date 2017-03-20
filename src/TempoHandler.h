/*
 * Generates 24 pulses per quarter note based on one of the
 * following sources:
    - MIDI timecode packets
    - Sync pulses
    - Internal clock generator

    If the clock source is the internal clock, the speed is
    determined by the position of the TEMPO_POT. Tempo range is
    40ms to 666ms

    After 12 pulses the sequencer advances
    The Volca sync pulses have to be interpolated

 * Calls a callback function every time the timer advances
 * Sends MIDI timecode packets
 * Sends sync pulses

 Does the tempohandler handle sync source switching as well? If so
 it needs to know about pins

 Are we going to pass the tempo pot pin value? Or the tempo pot pin number?

 */
 
#ifndef TempoHandler_h
#define TempoHandler_h

#define TEMPO_SOURCE_INTERNAL 0
#define TEMPO_SOURCE_MIDI     1
#define TEMPO_SOURCE_SYNC     2

class TempoHandler 
{
  public:
    inline void setHandleTempoEvent(void (*fptr)()) {
      tTempoCallback = fptr;
    }
    void update() {
      // Determine which source is selected for tempo
      if(false) {
        //TODO: implement midi clock source
      } else if(digitalRead(SYNC_DETECT)) {
        if(_source != TEMPO_SOURCE_SYNC) {
          Serial.println("Switching to SYNC as source");
        }
        _source = TEMPO_SOURCE_SYNC;
      } else {
        if(_source != TEMPO_SOURCE_INTERNAL) {
          Serial.println("Switching to INTERNAL as source");
        }
        _source = TEMPO_SOURCE_INTERNAL;
      }

      switch(_source) {
        case TEMPO_SOURCE_INTERNAL:
          update_internal();
          break;
        case TEMPO_SOURCE_MIDI:
          update_midi();
          break;
        case TEMPO_SOURCE_SYNC:
          update_sync();
          break;
      }
    }
  private:
    void (*tTempoCallback)();
    int pot_pin;
    uint8_t _source = 0;
    uint8_t _sync_pin_previous_value = 1;
    void update_midi() {

    }
    void update_sync() {
      uint8_t _sync_pin_value = digitalRead(SYNC_IN);

      if(_sync_pin_previous_value && !_sync_pin_value) {
        if (tTempoCallback != 0) {
          tTempoCallback();
        }
      }

      _sync_pin_previous_value = _sync_pin_value;
    }

    void update_internal() {
      // Read the position of the tempo pot
      // Increment the counter as soon as enough millis have passed
      // If the counter overflows, call the tempoHandler
    }
};

#endif