int val = 0;

const int LED = 24;
const int speekerPin = 13;

int flag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(speekerPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(1);

  if(val < 50){
    int octave3[] = {131,147,165,175,196,220,247};
    int octave4[] = {262,294,330,349,392,440,494};
    int a[] = {0,0,4,4,5,5,4,4,3,3,2,2,1,1,0,0};

    for(int i = 0; i < 16; i++){
      flag = flag == 0 ? 1 : 0;
      tone(speekerPin, octave4[a[i]],125);
      digitalWrite(LED,flag);
      delay(300);
    }
  }else{
    digitalWrite(LED,LOW);
  }

  Serial.println(val);
}