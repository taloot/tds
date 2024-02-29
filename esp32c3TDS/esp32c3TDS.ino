

char command[6]={0xA0,0x00,0x00,0x00,0x00,0xA0};

byte buffer[12] = {};
int TDS1,TDS2;
float TEMP1,TEMP2;

void setup()
{
  Serial.begin(115200);
 Serial1.begin(9600, SERIAL_8N1, 6, 7);
}

void loop()
{
    Serial1.write(command,6);
    delay(1000);
    
    for(int i=0;i<12;i++)
    {
      buffer[i] = (byte)Serial1.read();
      delay(2);
    }
    if(buffer[0]==0xAA && buffer[6]==0xAB)
    {
      TDS1 = buffer[1]*256+ buffer[2];
      TDS2 = buffer[3]*256+ buffer[4]; 
      TEMP1 = (buffer[7]*256+ buffer[8])/100.0; 
      TEMP2 = (buffer[9]*256+ buffer[10])/100.0; 
    }
     Serial.print("TDS1:");  
     Serial.println(TDS1); 
     Serial.print("TDS2:");  
     Serial.println(TDS2);             
     Serial.print("TEMP1:");  
     Serial.println(TEMP1); 
     Serial.print("TEMP2:");  
     Serial.println(TEMP2); 
    // delay(1000);       
}
