#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556
#define NTD8 622

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 112
//根據中部列出D的音節

int tune[] =
{
  NTD5, NTD3, NTD0, NTD0, NTD3, NTD2,
  NTD1, NTD2, NTD3, NTD5, NTD3, NTD5,
  NTD6, NTD3, NTD0, NTD0, NTD3, NTD2,
  NTD1, NTD2, NTD3, NTD5, NTD3, NTD5,
  NTD6, NTD4, NTD0, NTD0, NTD4, NTD3,
  NTD2, NTD3, NTD4, NTD6, NTD8, NTD6,
  NTD7, NTD6, NTD6, NTD5,
  NTD5, NTD4, NTD3, NTD2,
};
float durt[] =
{
  0.5, 0.5, 1, 1, 0.5, 0.5,
  0.5, 0.5, 0.5, 1, 0.5, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,
  0.5, 0.5, 0.5, 1, 0.5, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,
  0.5, 0.5, 0.5, 1, 0.5, 1,
  1 + 0.5, 0.5, 0.5, 1,
  1 + 0.5, 0.5, 1 + 1,
  0.5, 1 + 0.5, 1, 1,
};

//根據右邊的簡譜寫出音調和節奏 
int length;
int tonepin = 6; 
void setup()
{
  Serial.begin(9600);
  pinMode(tonepin, OUTPUT);
  length = sizeof(tune) / sizeof(tune[0]);
}
void loop()
{
  while (Serial.available())
  {
    int inByte = Serial.read();
    switch (inByte)
    {
      case 65:  //串口輸入為A時
        Serial.println("I'm not singing");  //回送I'm not singing
        digitalWrite(13, LOW);  //滅燈
        break;
      case 66:  //串口輸入為B時
        Serial.println("I'm singing");  //回送I'm singing
        digitalWrite(13, HIGH); //亮燈
        for (int x = 0; x < length; x++)
        {
          tone(tonepin, tune[x]*1.19);
          delay(500 * durt[x]);
          noTone(tonepin);
        } //演奏 *1.19使D調變成F調
        delay(2000);
        break;
    }
  }
} //上傳時拔掉藍線和黃線
