/* 
  Nokia Tune
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/
#define NOTE_B0  
#define NOTE_C1  
#define NOTE_CS1 
#define NOTE_D1  
#define NOTE_DS1 
#define NOTE_E1 
#define NOTE_F1  
#define NOTE_FS1 
#define NOTE_G1  
#define NOTE_GS1 
#define NOTE_A1  
#define NOTE_AS1 
#define NOTE_B1  
#define NOTE_C2  
#define NOTE_CS2 
#define NOTE_D2  
#define NOTE_DS2 
#define NOTE_E2  
#define NOTE_F2  
#define NOTE_FS2 
#define NOTE_G2  
#define NOTE_GS2 
#define NOTE_A2  
#define NOTE_AS2 
#define NOTE_B2  
#define NOTE_C3  
#define NOTE_CS3 
#define NOTE_D3  
#define NOTE_DS3 
#define NOTE_E3  
#define NOTE_F3  
#define NOTE_FS3 
#define NOTE_G3  
#define NOTE_GS3 
#define NOTE_A3  
#define NOTE_AS3 
#define NOTE_B3  
#define NOTE_C4  
#define NOTE_CS4 
#define NOTE_D4  
#define NOTE_DS4 
#define NOTE_E4  
#define NOTE_F4  
#define NOTE_FS4 
#define NOTE_G4  
#define NOTE_GS4 
#define NOTE_A4  
#define NOTE_AS4 
#define NOTE_B4  
#define NOTE_C5  
#define NOTE_CS5 
#define NOTE_D5  
#define NOTE_DS5 
#define NOTE_E5  
#define NOTE_F5  
#define NOTE_FS5 
#define NOTE_G5  
#define NOTE_GS5 
#define NOTE_A5  
#define NOTE_AS5 
#define NOTE_B5  
#define NOTE_C6  
#define NOTE_CS6 
#define NOTE_D6  
#define NOTE_DS6 
#define NOTE_E6  
#define NOTE_F6  
#define NOTE_FS6 
#define NOTE_G6  
#define NOTE_GS6 
#define NOTE_A6  
#define NOTE_AS6 
#define NOTE_B6  
#define NOTE_C7  
#define NOTE_CS7 
#define NOTE_D7  
#define NOTE_DS7 
#define NOTE_E7  
#define NOTE_F7  
#define NOTE_FS7 
#define NOTE_G7  
#define NOTE_GS7 
#define NOTE_A7  
#define NOTE_AS7 
#define NOTE_B7  
#define NOTE_C8  
#define NOTE_CS8 
#define NOTE_D8  
#define NOTE_DS8 
#define REST      


// change this to make the song slower or faster
int tempo = 180;

// change this to whichever pin you want to use
int buzzer = 11;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Nokia Ringtone 
  // Score available at https://musescore.com/user/29944637/scores/5266155
  
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}
