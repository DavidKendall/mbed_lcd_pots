#include <mbed.h>
#include <C12832.h>

enum {
  LPTL_X = 22,  // Left Pot Top Left X coordinate
  LPTL_Y = 2,   // Left Pot Top Left Y coordinate
  LPBR_X = 121, // Left Pot Bottom Right X coordinate
  LPBR_Y = 7,   // Left Pot Bottom Right Y coordinate
  RPTL_X = 22,  // Right Pot Top Left X coordinate
  RPTL_Y = 20,  // Right Pot Top Left Y coordinate
  RPBR_X = 121, // Right Pot Bottom Right X coordinate
  RPBR_Y = 25,  // Right Pot Bottom Right Y coordinate
};

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);
AnalogIn left(A0);
AnalogIn right(A1);
DigitalOut red(D5, 1);
DigitalOut green(D8, 1);
DigitalOut blue(D9, 1);

int main()
{
    lcd.cls();
    lcd.locate(0,2);
    lcd.printf("L:\n\n");
    lcd.printf("R:");
    lcd.rect(LPTL_X - 2, LPTL_Y - 2, LPBR_X + 2, LPBR_Y + 2, 1);
    lcd.rect(RPTL_X - 2, RPTL_Y - 2, RPBR_X + 2, RPBR_Y + 2, 1);

    while(true) {   // this is the third thread
        int lboundary = LPTL_X + (int)(100 * left.read());
        int rboundary = RPTL_X + (int)(100 * right.read());
        lcd.fillrect(LPTL_X, LPTL_Y, lboundary, LPBR_Y, 1);
        lcd.fillrect(lboundary, LPTL_Y, LPBR_X, LPBR_Y, 0);
        lcd.fillrect(RPTL_X, RPTL_Y, rboundary, RPBR_Y, 1);
        lcd.fillrect(rboundary, RPTL_Y, RPBR_X, RPBR_Y, 0);
        wait_ms(100);
    }
}
