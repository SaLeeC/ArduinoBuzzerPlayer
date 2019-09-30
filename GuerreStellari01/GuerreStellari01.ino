
/*
 * Leonardo SAMMARTANO
 * SaLe
 * SaLeeC
 * september 2019
*/


/* 
  Cantina band song from Star Wars
  Connect a piezo buzzer or speaker to pin 8 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/
/*

# ArduinoBuzzerPlayer
Play a music with the buzzer

FORK from Robson Couto, 2019
https://dragaosemchama.com/en/2019/02/songs-for-arduino/

IMPORTANTE
Nel file dal quale si è partito NON è indicato alcun accordo di licenza per cui 
si è scelto di applicare la MIT. Verificare sul sito del produttore del codice originale
eventuali limitazioni o impedimenti.

La presente versione è direttamente derivata dal lavoro di Robson Couto.
La differenza fra i due codici sta nel gestire 8 LED per accompagnare la musica
con l'accensione di un LED per ogni nota e uno per la pausa.

Il codice è stato verificato sulla piastra MAKER UNO.
La piastra MAKER UNO è basata su un core Arduino Uno ed è dotata di un LED per ogni
piedino digitale e di un buzzer sul piedino 8, questo permette di far girare il codice
senza l'aggiunta di un solo componente e senza richiedere nessuna breadboard.

IMPORTANT
No license agreement is indicated in the original source file.
We have chosen to apply the MIT license.
Check the original code on the manufacturer's website
any limitations or impediments.

This version is directly derived from the work of Robson Couto.
The difference between the two codes is to manage 8 LEDs to accompany the music
by lighting one LED for each note and one for the pause.

The code has been verified on the MAKER UNO plate.
The MAKER UNO plate is based on an Arduino Uno core and is equipped with an LED for
each digital pin and a buzzer on pin 8, this allows you to run the code without
adding a single component and without requiring any breadboard.

*/


// change this to whichever pin you want to use
int buzzer = 8;

#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 108;


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  
  // Dart Vader theme (Imperial March) - Star wars 
  // Score available at https://musescore.com/user/202909/scores/1141521
  // The tenor saxophone part was used

//A -> 13
//B -> 12
//C -> 11
//D -> 10
//E -> 9
//F -> 7
//G -> 6
//REST -> 5
  
  
  NOTE_AS4,8, 13, NOTE_AS4,8, 13, NOTE_AS4,8, 13,//1
  NOTE_F5,2, 7, NOTE_C6,2, 11,
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F6,2, 7, NOTE_C6,4, 11,
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F6,2, 7, NOTE_C6,4, 11,
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_AS5,8, 13, NOTE_G5,2, 6, NOTE_C5,8, 11, NOTE_C5,8, 11, NOTE_C5,8, 11,
  NOTE_F5,2, 7, NOTE_C6,2, 11,
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F6,2, 7, NOTE_C6,4, 11,  
  
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F6,2, 7, NOTE_C6,4, 11, //8  
  NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_AS5,8, 13, NOTE_G5,2, 6, NOTE_C5,-8, 11, NOTE_C5,16, 11,
  NOTE_D5,-4, 10, NOTE_D5,8, 10, NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F5,8, 7,
  NOTE_F5,8, 7, NOTE_G5,8, 6, NOTE_A5,8, 13, NOTE_G5,4, 6, NOTE_D5,8, 10, NOTE_E5, 4, 9, NOTE_C5,-8, 11, NOTE_C5,16, 11,
  NOTE_D5,-4, 10, NOTE_D5,8, 10, NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F5,8, 7,
  
  NOTE_C6,-8, 11, NOTE_G5,16, 6, NOTE_G5,2, 6, REST,8, 5, NOTE_C5,8, 11,//13
  NOTE_D5,-4, 10, NOTE_D5,8, 10, NOTE_AS5,8, 13, NOTE_A5,8, 13, NOTE_G5,8, 6, NOTE_F5,8, 7,
  NOTE_F5,8, 7, NOTE_G5,8, 6, NOTE_A5,8, 13, NOTE_G5,4, 6, NOTE_D5,8, 10, NOTE_E5,4, 9, NOTE_C6,-8, 11, NOTE_C6,16, 11,
  NOTE_F6,4, 7, NOTE_DS6,8, 10, NOTE_CS6,4, 11, NOTE_C6,8, 11, NOTE_AS5,4, 13, NOTE_GS5,8, 6, NOTE_G5,4, 6, NOTE_F5,8, 7,
  NOTE_C6,1, 11
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 3;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 3; thisNote = thisNote + 3) 
  {
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

    //before play the note turn on light the corresponding LED
    digitalWrite(melody[thisNote + 2], HIGH);
    
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    
    // stop the waveform generation before the next note.
    noTone(buzzer);
    //Shut down all LED
    for (int LEDOFF = 5; LEDOFF<14; LEDOFF = LEDOFF + 1)
    {
      digitalWrite(LEDOFF,LOW);
    }
  }
}

void loop() 
{
  // no need to repeat the melody.
}
