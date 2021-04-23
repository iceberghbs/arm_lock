#include "mbed.h"
#include "stm32f413h_discovery_ts.h"
#include "stm32f413h_discovery_lcd.h"
#include "C12832.h"
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

TS_StateTypeDef TS_State = { 0 };

 char* Keytable[]={"1","2","3","F",
                  "4","5","6","E",
                  "7","8","9","D",
                  "A","0","B","C"
                  };
                
char* ch[3];
int i;
int j;
int a;
int c=1;

int main() {
    printf("Draw on the screen!\n");

    BSP_LCD_Init();                                     

    /* Touchscreen initialization */
    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) 
    {
        printf("BSP_TS_Init error\n");                 
    }
    
        /* Clear the LCD */
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    
        /* Set Touchscreen Demo1 description */
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);           
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), BSP_LCD_GetXSize());  
    
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(7.5,7.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+1*5+52.5,7.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+2*5+2*52.5,7.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+3*5+3*52.5,7.5,52.5,52.5);
    
    BSP_LCD_FillRect(7.5,7.5+1*5+52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+1*5+52.5,7.5+1*5+52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+2*5+2*52.5,7.5+1*5+52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+3*5+3*52.5,7.5+1*5+52.5,52.5,52.5);
    
    BSP_LCD_FillRect(7.5,7.5+2*5+2*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+1*5+52.5,7.5+2*5+2*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+2*5+2*52.5,7.5+2*5+2*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+3*5+3*52.5,7.5+2*5+2*52.5,52.5,52.5);
    
    BSP_LCD_FillRect(7.5,7.5+3*5+3*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+1*5+52.5,7.5+3*5+3*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+2*5+2*52.5,7.5+3*5+3*52.5,52.5,52.5);
    BSP_LCD_FillRect(7.5+3*5+3*52.5,7.5+3*5+3*52.5,52.5,52.5);  
    
    BSP_LCD_SetTextColor(LCD_COLOR_RED);              
    BSP_LCD_SetFont(&Font24); 
    
    BSP_LCD_DisplayStringAt(52.5/3+7.5, 52.5/3+5, (uint8_t *)"1", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+52.5+5, 52.5/3+5, (uint8_t *)"2", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+2*52.5+2*5, 52.5/3+5, (uint8_t *)"3", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+3*52.5+3*5, 52.5/3+5, (uint8_t *)"F", LEFT_MODE); 
    
    BSP_LCD_DisplayStringAt(52.5/3+7.5, 52.5/3+5+52.5+5, (uint8_t *)"4", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+52.5+5, 52.5/3+5+52.5+5, (uint8_t *)"5", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+2*52.5+2*5, 52.5/3+5+52.5+5, (uint8_t *)"6", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+3*52.5+3*5, 52.5/3+5+52.5+5, (uint8_t *)"E", LEFT_MODE); 
    
    BSP_LCD_DisplayStringAt(52.5/3+7.5, 52.5/3+5+2*52.5+2*5, (uint8_t *)"7", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+52.5+5, 52.5/3+5+2*52.5+2*5, (uint8_t *)"8", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+2*52.5+2*5, 52.5/3+5+2*52.5+2*5, (uint8_t *)"9", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+3*52.5+3*5, 52.5/3+5+2*52.5+2*5, (uint8_t *)"D", LEFT_MODE);    

    BSP_LCD_DisplayStringAt(52.5/3+7.5, 52.5/3+5+3*52.5+3*5, (uint8_t *)"A", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+52.5+5, 52.5/3+5+3*52.5+3*5, (uint8_t *)"0", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+2*52.5+2*5, 52.5/3+5+3*52.5+3*5, (uint8_t *)"B", LEFT_MODE); 
    BSP_LCD_DisplayStringAt(52.5/3+7.5+3*52.5+3*5, 52.5/3+5+3*52.5+3*5, (uint8_t *)"C", LEFT_MODE);  
   
        lcd.locate(26,15);
        
    int cnt=0;
    char digits[4] = {'_', '_', '_', '_'};
    char code[4] = {'n', 'u', 'l', 'l'};
    char code_reg[4];
    bool lock = 0;
        
    while (1) {
        BSP_TS_GetState(&TS_State);
        if(TS_State.touchDetected) {

            uint16_t x1 = TS_State.touchX[0]; 
            uint16_t y1 = TS_State.touchY[0]; 

                if (x1>10 and x1<55){i=0;}
            else if (x1>65 and x1<115){i=1;}
            else if (x1>125 and x1<177){i=2;}
            else if (x1>182 and x1<230){i=3;}

                if (y1>10 and y1<55){j=0;}
            else if (y1>65 and y1<115){j=1;}
            else if (y1>125 and y1<177){j=2;}
            else if (y1>182 and y1<230){j=3;} 
            
            lcd.locate(5, 5); lcd.printf("                 ");  //clean lcd

            if (i==0 && j==0){lcd.locate(55,5);lcd.printf("1");wait(.1); code_reg[cnt] = '1'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==1 && j==0){lcd.locate(55,5);lcd.printf("2");wait(.1); code_reg[cnt] = '2'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==2 && j==0){lcd.locate(55,5);lcd.printf("3");wait(.1); code_reg[cnt] = '3'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==3 && j==0){lcd.locate(55,5);lcd.printf("F");wait(.1); code_reg[cnt] = 'F'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==0 && j==1){lcd.locate(55,5);lcd.printf("4");wait(.1); code_reg[cnt] = '4'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==1 && j==1){lcd.locate(55,5);lcd.printf("5");wait(.1); code_reg[cnt] = '5'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==2 && j==1){lcd.locate(55,5);lcd.printf("6");wait(.1); code_reg[cnt] = '6'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==3 && j==1){lcd.locate(55,5);lcd.printf("E");wait(.1); code_reg[cnt] = 'E'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==0 && j==2){lcd.locate(55,5);lcd.printf("7");wait(.1); code_reg[cnt] = '7'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==1 && j==2){lcd.locate(55,5);lcd.printf("8");wait(.1); code_reg[cnt] = '8'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==2 && j==2){lcd.locate(55,5);lcd.printf("9");wait(.1); code_reg[cnt] = '9'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==3 && j==2){lcd.locate(55,5);lcd.printf("D");wait(.1); code_reg[cnt] = 'D'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==0 && j==3){lcd.locate(55,5);lcd.printf("A");wait(.1); code_reg[cnt] = 'A'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==1 && j==3){lcd.locate(55,5);lcd.printf("0");wait(.1); code_reg[cnt] = '0'; digits[cnt] = '*'; cnt = cnt + 1;}
            if (i==2 && j==3)
            {   
                lcd.locate(55,5);lcd.printf("B");wait(.1);
                if (cnt==4)
                {
                    if (lock==0) {code[0] = code_reg[0]; code[1] = code_reg[1]; code[2] = code_reg[2]; code[3] = code_reg[3]; lock = 1;}
                    else
                    {
                        if (code[0]==code_reg[0]&&code[1]==code_reg[1]&&code[2]==code_reg[2]&&code[3]==code_reg[3])
                        {
                            lcd.locate(40, 5);lcd.printf("CE323 A1");
                        }
                    }
                    cnt = 0;
                }
                
            }
            if (i==3 && j==3)
            {
                lcd.locate(55,5);lcd.printf("C");wait(.1); 
                if (cnt > 0) {cnt = cnt - 1; digits[cnt] = '_'; code_reg[cnt] = -1;}
            }

            if (cnt==4){lcd.locate(5, 5); lcd.printf("press B");}
            if (cnt==5 ){cnt = 0;}
            
            if (cnt==0)
            {
                digits[3] = '_'; digits[2] = '_'; digits[1] = '_'; digits[0] = '_';
                lcd.locate(5, 5); lcd.printf("      ");
            }
            
   
        }
        lcd.locate(20, 20);lcd.printf("code: %c %c %c %c", digits[0], digits[1], digits[2], digits[3]);
        // lcd.locate(90, 20);lcd.printf("%d", cnt);
        // lcd.locate(110, 20);lcd.printf("%d", lock);
    }
}
   
   
