#define freq_pin A0 // Aqui definimos o pino analógico do potênciometro de frequência, no caso, o A0.

const int led_pins[3] = {4, 3, 2}; // Aqui definimos os pinos para os leds que demonstram em qual frequência estamos: VERMELHO - PINO DIGITAL 4, AMARELO - PINO DIGITAL 3, VERDE - PINO DIGITAL 2

// Aqui definimos os pinos dos botões que utilizaremos, o A, B, C e o de Envio.
const int A_button_pin = 5; // A - PINO DIGITAL 5
const int B_button_pin = 6; // B - PINO DIGITAL 6
const int C_button_pin = 7; // C - PINO DIGITAL 7
const int send_button_pin = 8; // Enviar - PINO DIGITAL 8

const int max_chars = 2; // Aqui setamos o número máximo de caracteres a ser enviado, essa linha é meio inútil já que na tabela possuem apenas dois caracteres referenciando uma letra, tipo "AB" = "C", mas deixem ela aqui!

int old_frequency, frequency; // Aqui guardamos a frequência antiga e a atual para codificarmos certinho depois.

String cipher_text, raw_text, code; // Aqui criamos as variáveis para os textos cifrados/normais.

bool button_a, button_b, button_c, send_button; // Aqui são variáveis de controle dos botões, para não serem apertados mais de uma vez caso o segure.

void setup() // Aqui iniciamos a função principal
{
  pinMode(A_button_pin, INPUT);
  pinMode(B_button_pin, INPUT);
  pinMode(C_button_pin, INPUT);
  pinMode(send_button_pin, INPUT);
  
  Serial.begin(9600);
}

// Aqui vemos a função de encriptação, ela recebe um número que pode ser a combinação de dois números inteiros, em que 1 representa A, 2 representa B e 3 representa C, por exemplo: "12" = "AB", pois 1 = A e 2 = B.
// Após isso, ela verifica de acordo com a tabela e com a frequência em que você está, a letra a ser criptografada na mensagem cifrada.
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

int clicks = 0; // Variável de controle para sabermos quantos botões já foram apertados

// Aqui recebemos um sinal do botão de envio e iniciamos a encriptação, essa função pega o code já com os números inteiros e envia para a função encript.
void start_cipher(){
    encript();
    clicks = 0;
    code = "";
  	//cipher_text = cipher_text + " "; // Uncomment this line to print a separated cipher char
}

// Aqui temos a função que efetua o clique dos botões, ela também verifica se a quantidade de botões apertados não ultrapassa o max_chars e adiciona o número ao texto do code.
void button_click(char button_char, char letter){
  if(clicks < max_chars){
   	code = code + button_char;
    if(clicks == 0){
      cipher_text = cipher_text + (frequency != old_frequency ? frequency : '\0') + letter;
    }else{
      cipher_text = cipher_text + letter;
    }
    clicks++;
  }
}

// Aqui temos a função que muda a frequência.
void change_frequency(int freq){
  if(freq != frequency){
    old_frequency = frequency;
    frequency = freq;
  }
}

// Aqui temos o coração do código, o loop.
void loop()
{ 
  // Verificações para saber qual botão está apertado
  if(digitalRead(A_button_pin) == 1 && button_a == false){
    button_a = true;
    button_click('1', 'A'); // A função button_click envia por meio de dois argumentos o número e sua letra correspondente, por exemplo: '1' = 'A'.
  }else if(digitalRead(B_button_pin) == 1 && button_b == false){
    button_b = true;
    button_click('2', 'B');
  }else if(digitalRead(C_button_pin) == 1 && button_c == false){
    button_c = true;
    button_click('3', 'C');
  }
  
  // Aqui mudamos a frequência e a luminosidade dos leds dependendo de qual frequência estamos.
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
  
  // Aqui é a verificação do botão de enviar
  if(digitalRead(send_button_pin) == 1 && send_button == false){
	  send_button = true;
    if(clicks > 0){
    	start_cipher(); 
    }
  }
  
  // Aqui temos um reset das variáveis de controle dos botões, para "desapertá-los" dentro do código.
  if(digitalRead(A_button_pin) == 0)
    button_a = false;
  if(digitalRead(B_button_pin) == 0)
    button_b = false;
  if(digitalRead(C_button_pin) == 0)
    button_c = false;
  if(digitalRead(send_button_pin) == 0)
    send_button = false;
}