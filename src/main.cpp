#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);
AnalogIn left(A0);
AnalogIn right(A1);
DigitalOut red(D5);
DigitalOut green(D8);
DigitalOut blue(D9);

int main()
{
    red = 1;
    green = 1;
    blue = 1;
    lcd.cls();
    lcd.locate(0,2);
    lcd.printf("L:\n\n");
    lcd.printf("R:");
    lcd.rect(20, 0, 123, 9, 1);
    lcd.rect(20, 18, 123, 27, 1);

    while(true) {   // this is the third thread
        int lboundary = 22 + (int)(100 * left.read());
        int rboundary = 22 + (int)(100 * right.read());
        lcd.fillrect(22, 2, lboundary, 7, 1);
        lcd.fillrect(lboundary, 2, 121, 7, 0);
        lcd.fillrect(22, 20, rboundary, 25, 1);
        lcd.fillrect(rboundary, 20, 121, 25, 0);
        wait_ms(100);
    }
}
