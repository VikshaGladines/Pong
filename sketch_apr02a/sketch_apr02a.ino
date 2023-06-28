#include <Gamebuino-Meta.h> 


 void setup() {
  gb.begin();
 }
 int xBall = 37;
 int yBall = 32;
 int trajBallX = 1;
 int trajBallY = 1;
 int yRaquette1 = 25;
 int xRaquette1 = 5;
 int yRaquette2 = 25; 
 int xRaquette2 = 70;
 int scorej1 = 0;
 int scorej2 = 0;
 
 void loop() {
  while(!gb.update());
  gb.display.clear();
  gb.display.setColor(BLACK);
  gb.display.print(" ");
  gb.display.setColor(WHITE, RED);
  gb.display.setFontSize(2);
  gb.display.print(scorej1);
  gb.display.setColor(BLACK);
  gb.display.print("      ");
  gb.display.setColor(WHITE, BLUE);
  gb.display.print(scorej2);

  /* init ball */
  gb.display.setColor(YELLOW);
  gb.display.fillCircle(xBall, yBall, 3);
 
  if (xBall < 0){
    scorej2++;
    xBall = 37;
    yBall = 32;
  }
 if (xBall > gb.display.width()) { 
    scorej1++;
    xBall = 37;
    yBall = 32;
  }
  xBall = xBall + trajBallX;

 if (yBall < 0){
    trajBallY = 1;
  }
   if ( yBall > gb.display.height()) {
    trajBallY = -1;
  }
  yBall = yBall + trajBallY;
  
  /* init raquette 1 */
  gb.display.setColor(RED);
  gb.display.fillRect(xRaquette1, yRaquette1, 4, 15);
  
  if (gb.buttons.repeat(BUTTON_DOWN,0)) {
    yRaquette1 = yRaquette1 + 3;
  }
  if (gb.buttons.repeat(BUTTON_UP,0)) {
    yRaquette1 = yRaquette1 - 3;
  } 
  /*centre*/
  if (yBall - 3 >= yRaquette1 + 5 && yBall - 3 <= yRaquette1 + 10 && xBall /*- 3*/ == xRaquette1 + 4) {
    gb.display.setColor(RED);
    trajBallX++;
  }
  /*haut*/
  if ( yBall >= yRaquette1 && yBall <= yRaquette1 + 5 && xBall /*- 3*/ == xRaquette1 + 4) {
    gb.display.setColor(RED);
    trajBallX++;
  }
  /*bas*/
  if ( yBall >= yRaquette1 + 10 && yBall <= yRaquette1 + 15 && xBall /*- 3*/ == xRaquette1 + 4) {
    gb.display.setColor(RED);
    trajBallX++;
   }  
  
    /* init raquette 2 */
  gb.display.setColor(BLUE);
  gb.display.fillRect(xRaquette2, yRaquette2, 4, 15);
  
  if (gb.buttons.repeat(BUTTON_A,0)) {
    yRaquette2 = yRaquette2 + 3;
  }
  if (gb.buttons.repeat(BUTTON_B,0)) {
    yRaquette2 = yRaquette2 - 3;
  }
  /*centre*/
  if (yBall >= yRaquette2 + 5 && yBall <= yRaquette2 + 10 && xBall /*+ 3*/ == xRaquette2) {
    gb.display.setColor(BLUE);
    trajBallX = -1;
  }
  /*haut*/
  if ( yBall >= yRaquette2 && yBall <= yRaquette2 + 5 && xBall /*+ 3*/ == xRaquette2) {
    gb.display.setColor(BLUE);
    trajBallX = -1;
  }
  /*bas*/
  if ( yBall >= yRaquette2 + 10 && yBall <= yRaquette2 + 15 && xBall /*+ 3*/ == xRaquette2) {
    gb.display.setColor(BLUE);
    trajBallX = -1;
  } 

  if (scorej1 >= 7){
    gb.display.clear();
    gb.display.setColor(RED);
    gb.display.println("joueur");
    gb.display.println("rouge");
    gb.display.println("a gagné");
  }

   if (scorej2 >= 7){
    gb.display.clear();
    gb.display.setColor(BLUE);
    gb.display.println("joueur");
    gb.display.println("bleu");
    gb.display.println("a gagné");
  }

  if (gb.buttons.pressed(BUTTON_MENU)){
    scorej1 = 0;
    scorej2 = 0;
    xBall = 37;
    yBall = 32;
  }

  
 }



