//Code

int pin = 5;

int length = 34; // the number of notes
char notes[] = "geg geg agfedefefgcccccdefggddfedc"; // a space represents a rest
double beats[] = {1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 3}; //22
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(pin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
//  char* words[] = {"I", "love", "you", " ", "You", "love", "me.", " ", "We're", "a", "hap-", "py", "fam-", "i-", "ly", "with", "a", "great", "big", "hug", "and", "a", "kiss", "from", "me", "to", "you,","won't", "you", "say", "you","love", "me", "too?"  

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

////will print words along with each note
//  for(int i = 0; i < length; i++) {
//     if (words[i] == 
//  }

void setup() {
  pinMode(pin, OUTPUT);
  Serial.print(9600);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
  
    }
 n
    // pause between notes
    delay(tempo / 2); 
  }
}
