//#include <SoftwareSerial.h>



/**********************************************************************************
 * 描述    ：Arduino UNO, 波特率：9600, 串口读取双路TDS模块浓度数据 
 * 硬件连接： 
 * 双路TDS模块：3.3V -> 3.3V; RX -> D1; TX -> D0; GND -> GND;  ----硬件串口   波特率：9600
 * USB转TTL模块：GND -> GND; RX -> D3; TX -> D2;              ----模拟软串口  波特率：9600
 * 功能描述：硬件串口外接双路TDS模块读取TDS浓度数据
 *          软件模拟串口输出TDS浓度数据
 * 使用说明：先下载好程序再接线
**********************************************************************************/
//#include <SoftwareSerial.h>

//实例化软串口
//SoftwareSerial Serial(2, 3); // RX, TX

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
