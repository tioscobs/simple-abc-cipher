#define freq_pin A0

const int led_pins[3] = {4, 3, 2};

const int A_button_pin = 5;
const int B_button_pin = 6;
const int C_button_pin = 7;
const int send_button_pin = 8;

const int max_chars = 2;

int old_frequency, frequency;

String cipher_text, raw_text, code;

bool button_a, button_b, button_c, send_button;

void setup()
{
  pinMode(A_button_pin, INPUT);
  pinMode(B_button_pin, INPUT);
  pinMode(C_button_pin, INPUT);
  pinMode(send_button_pin, INPUT);
  
  Serial.begin(9600);
}

void encript(){
  if(code == "1"){
    raw_text = raw_text + (frequency == 0 ? "A" : (frequency == 1 ? "J" : "S"));
  }else if(code == "2"){
    raw_text = raw_text + (frequency == 0 ? "B" : (frequency == 1 ? "K" : "T"));
  }else if(code == "3"){
    raw_text = raw_text + (frequency == 0 ? "C" : (frequency == 1 ? "L" : "U"));
  }else if(code == "12"){
    raw_text = raw_text + (frequency == 0 ? "D" : (frequency == 1 ? "M" : "V"));
  }else if(code == "13"){
    raw_text = raw_text + (frequency == 0 ? "E" : (frequency == 1 ? "N" : "W"));
  }else if(code == "21"){
    raw_text = raw_text + (frequency == 0 ? "F" : (frequency == 1 ? "O" : "X"));
  }else if(code == "23"){
    raw_text = raw_text + (frequency == 0 ? "G" : (frequency == 1 ? "P" : "Y"));
  }else if(code == "31"){
    raw_text = raw_text + (frequency == 0 ? "H" : (frequency == 1 ? "Q" : "Z"));
  }else if(code == "32"){
    raw_text = raw_text + (frequency == 0 ? "I" : (frequency == 1 ? "R" : " "));
  }
  Serial.println("Text: " + raw_text);
  Serial.println("Cipher: "+ cipher_text);
}

int clicks = 0;

void start_cipher(){
    encript();
    clicks = 0;
    code = "";
  	//cipher_text = cipher_text + " "; // Un-comment this line to print a separated cipher char
}

void button_click(char button_char, char letter){
  if(clicks < max_chars){
   	code = code + button_char;
    if(clicks == 0){
      cipher_text = cipher_text + (frequency != old_frequency ? frequency : '\0') + letter;
    }else{
      cipher_text = cipher_text + letter;
    }
    clicks++;
    //Serial.println(code);
  }
}

void change_frequency(int freq){
  if(freq != frequency){
    old_frequency = frequency;
    frequency = freq;
  }
}

void loop()
{ 
  if(digitalRead(A_button_pin) == 1 && button_a == false){
    button_a = true;
    button_click('1', 'A');
  }else if(digitalRead(B_button_pin) == 1 && button_b == false){
    button_b = true;
    button_click('2', 'B');
  }else if(digitalRead(C_button_pin) == 1 && button_c == false){
    button_c = true;
    button_click('3', 'C');
  }
  
  if(analogRead(freq_pin) <= 341){
    change_frequency(0);
    digitalWrite(led_pins[0], HIGH);
    digitalWrite(led_pins[1], LOW);
    digitalWrite(led_pins[2], LOW);
  }else if(analogRead(freq_pin) > 341 && analogRead(freq_pin) <= 682){
    change_frequency(1);
    digitalWrite(led_pins[0], LOW);
    digitalWrite(led_pins[1], HIGH);
    digitalWrite(led_pins[2], LOW);
  }else if(analogRead(freq_pin) > 682){
    change_frequency(2);
    digitalWrite(led_pins[0], LOW);
    digitalWrite(led_pins[1], LOW);
    digitalWrite(led_pins[2], HIGH);
  }
  
  if(digitalRead(send_button_pin) == 1 && send_button == false){
	  send_button = true;
    if(clicks > 0){
    	start_cipher(); 
    }
  }
  
  if(digitalRead(A_button_pin) == 0)
    button_a = false;
  if(digitalRead(B_button_pin) == 0)
    button_b = false;
  if(digitalRead(C_button_pin) == 0)
    button_c = false;
  if(digitalRead(send_button_pin) == 0)
    send_button = false;
}