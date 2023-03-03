import processing.sound.*;
SoundFile motor;
SoundFile buzina;

int x = -50;
int y = -75; 
float newX = x, newY = y;
float theta; 
PGraphics pg;
int tothe = 0;
boolean wiping = false;
int delay = 0;
boolean headlight = false;
boolean lArrow = false;
boolean rArrow = false;
int ArrowDelay = 0;
float yEarViewRetract = 0;
float xEarViewRetract = 0;
boolean earView = false;
boolean retracting = true;
boolean lMotor = false;
float[] posX = new float[20];
float[] posY = new float[20];
void setup(){
    size(1000,650);
    frameRate(60);
    for(int i = 0; i < 20; i++){
      posX[i] = random(0,width);
      posY[i] = random(0,height/2);
    }
    motor = new SoundFile(this, "Ligando.mp3");
    buzina = new SoundFile(this, "audioZap.mp3");
}

void draw(){
  moon();

  strokeWeight(2);

  //windowPainting
  noStroke();
  fill(#2EC900,300);
  
  quad(209,178, 163, 295,820, 303, 773, 177);
  stroke(#000000);
  //top arc
  fill(#14FF00,300);
  arc(490, 185, 570, 100, PI+0.1, TWO_PI-0.1);
  
  //left window arc
  line(206,180,165,290);
  
  //right window arc
  line(773,180,815,290);
  noStroke();
  

  //middle painting
  rect(159,300,660,220);
  rect(155,500,5,20);
  fill(#14FF00,200);
  //line(823, 298, 823, 317);
  quad(160,295, 155,300,823, 317,823, 296);
  fill(#14FF00,200);
  
  
  stroke(#000000);
  //left arc
  arc(177, 438, 60, 260, PI-0.7, PI+QUARTER_PI+0.2);
  line(164, 290, 157, 298);
  line(157, 298, 157, 317);
  line(157, 316, 160, 320);
  line(160, 320, 160, 333);
  

  stroke(#000000,200);
  //right arc
  arc(803, 426, 60, 217, -1, QUARTER_PI+0.3);
  line(823, 298, 815, 290);
  line(823, 298, 823, 317);
  line(823, 316, 820, 320);
  line(819.6, 333, 820, 320);
  
  bumper();
  
  //middle left arc
  arc(195, 446, 20, 265, PI-0.7, PI+QUARTER_PI+0.2);
  //middle right arc
  arc(785, 431, 15, 226, -1, QUARTER_PI+0.3);
  
  //middle horizontal lines
  line(195, 297, 790, 300);
  line(161, 293, 195, 297);
  line(790, 300,820, 295);
  //middle-top horizontal arc
  arc(490, 176, 561, 10,0 , PI);
  
  
  //left-botton window arc
  fill(#363636);
  arc(347, 285, 268, 20,0-0.05 , PI+0.05);
  //left-top window arc
  arc(362, 193, 230, 15, PI+0.1, TWO_PI-0.1);
  //left-left window line
  line(247, 192, 212, 285);
  //left-right window line 
  line(476, 192, 480, 284);
  
  //right-botton window arc
  arc(631, 285, 267, 20,0-0.05 , PI+0.05);
  //right-top window arc
  arc(615, 193, 230, 15, PI+0.1, TWO_PI-0.1);
  //right-left window line
  line(500, 192, 497, 284);
  //right-right window line
  line(729, 192, 765, 285);
  
  fill(#00F7E5,300);
  //left-side window
  quad(204,192, 171, 284, 187, 286, 219, 192);
  
  //right-side window
  quad(758,192,791, 292, 810, 289, 775, 194);
  
  //middle V
  fill(#25E533,0);
  line(184, 332,350, 413);
  arc(277, 800, 500, 810, PI + HALF_PI + 0.3,TWO_PI-0.8);
  arc(698, 800, 500, 810, PI+0.8,TWO_PI - HALF_PI-0.3);
  line(797, 331,624, 413);
  line(509, 530, 523, 509);
  line(464, 530, 451, 509);
  arc(487 , 509 , 65 , 60 , 0.8 , PI-0.8);
  arc(190, 313, 20, 46, PI-1, PI+QUARTER_PI);
  arc(792, 315, 20, 46, PI+HALF_PI+QUARTER_PI, TWO_PI+0.8);
  
  logo();
  headLights();
  litteHeadlights();
  
  
  //left windows borders
  fill(#363636,300);
  quad(248,192, 212, 284, 220, 286, 255, 192);
  quad(470,192, 475, 285, 482, 285, 477, 192);
  quad(204,192, 171, 284, 176, 286, 209, 192);
  
   //right windows borders
  quad(722,192, 757, 285, 766, 286, 729, 192);
  quad(501,192, 498, 285, 503, 285, 507, 192);
  quad(770,194,806, 292, 810, 289, 775, 194);
  
  //right window paint
  fill(#00F7E5,300);
  quad(507, 192,503, 285,757, 285, 722,192);
  fill(#0AE4FF,300);
  quad(507, 192,503, 285,738, 235, 722,192);
  
  //left window paint
  quad(255, 192,220, 286,475, 285, 470,192);
  fill(#00F7E5,300);
  quad(255, 192,220, 286,473, 235, 470,192);
  
  //middle vertical lines
  stroke(#000000);
  line(235, 179,195, 296);
  line(489, 181,489, 297);
  line(740, 179,782, 299);
  
  earViewers();
  tires();
  
  //wipers
  strokeWeight(3);
  //left wiper
  translate(340, 286);
  line(0, 0, newX, newY);
  fill(#000000);
  ellipse(0,0,7,7);
  //right wiper
  translate(280, 0);
  ellipse(0,0,7,7);
  line(0, 0, newX, newY);
    
  
  if(wiping == true){
    newX = x*cos(theta)- y*sin(theta);
    newY = x*sin(theta)+ y*cos(theta);
    if(theta < PI/2 + 0.55 && tothe == 0) {
      theta = theta + PI/15;
      if(theta > PI/2 + 0.55) tothe = 1;
    }
    if (tothe == 1) {
      theta = theta - PI/15;
      if(theta < -PI/2 + 0.8) tothe = 0;
    }
  }
  fill(#000000);
}

//earviewers
void earViewers(){
  strokeWeight(2);
  //left rear view
  fill(#266C03,120);
  if(earView == true){
    if(retracting == true){
      xEarViewRetract+=1;
      yEarViewRetract += 0.09;
    }
    else{
      xEarViewRetract-=1;
      yEarViewRetract -= 0.09;
    }
    if((xEarViewRetract >= 40 && retracting == true) || (xEarViewRetract <= 0 && retracting == false) ){
      retracting = !retracting;
      earView = false;
    };
  }
  quad(205, 240, 196,265, 205, 266, 213, 241);
  quad(214, 243, 209,260, 214, 261, 219, 244);
  rotate(0.3);
  fill(#50524E);
  ellipse(203+xEarViewRetract ,153 + yEarViewRetract,45,38);
  fill(#757674);
  noStroke();
  ellipse(203 + xEarViewRetract,153 + yEarViewRetract,30,25);
  stroke(#000000);
  
  
  strokeWeight(5);
  stroke(#000000);
  line(203 +xEarViewRetract, 153 +yEarViewRetract, 195 +xEarViewRetract, 160+yEarViewRetract);;
  stroke(#071500);
  strokeWeight(3);
  line(170+xEarViewRetract, 160+yEarViewRetract, 275, 168);
  rotate(-0.3);
  
  //right rear view
  strokeWeight(2);
  fill(#266C03,120);
  quad(764, 245, 772,265,779, 266, 771, 245);
  quad(760, 248, 764,260, 768, 261, 763, 247);
  
 
  fill(#50524E);
  ellipse(822-xEarViewRetract,204+xEarViewRetract/1.6,48,30);
  fill(#757674);
  noStroke();
  ellipse(822-xEarViewRetract,204+xEarViewRetract/1.6,34,20);
  stroke(#000000);
  
  strokeWeight(5);
  stroke(#000000);
  line(826-xEarViewRetract, 206+xEarViewRetract/1.6, 822-xEarViewRetract,204+xEarViewRetract/1.6);
  stroke(#071500);
  strokeWeight(3);
  line(763, 247, 846-xEarViewRetract, 195+xEarViewRetract/1.6);
  
}

//tires
void tires(){
  //left tire
  fill(#000000, 120);
  stroke(0);
  line(193, 627, 240, 626);
  arc(210, 575, 70, 120, HALF_PI+0.5, PI+0.05);
  fill(#000000, 140);
  arc(220, 578, 70, 120, HALF_PI+0.8, PI);
  arc(230, 578, 70, 120, HALF_PI+0.8, PI);
  arc(240, 579, 70, 120, HALF_PI+0.8, PI);
  arc(250, 579, 70, 120, HALF_PI+0.8, PI);
  fill(#000000, 90);
  arc(240, 580, 25, 90, HALF_PI-1.58, PI+0.05);
  fill(#000000, 120);
  arc(240, 580, 5, 50, HALF_PI-1.58, PI+0.05);

 //right tire
  stroke(0);
  line(734, 628, 776, 628);
  arc(760, 575, 70, 120, -0.03, HALF_PI-0.5);
  fill(#000000, 90);
  arc(735, 582, 25, 90, HALF_PI-1.7, PI+0.05);
  fill(#000000, 120);
  arc(755, 575, 70, 120, +0.09, HALF_PI-0.7);
  arc(745, 575, 70, 120, +0.09, HALF_PI-0.7);
  arc(735, 575, 70, 120, +0.09, HALF_PI-0.7);
  arc(725, 577, 70, 120, +0.09, HALF_PI-0.7);
  fill(#000000, 120);
  arc(735, 580, 5, 50, HALF_PI-1.58, PI+0.05);
}

//parachoque
void bumper(){
  //botton arc 1
  fill(#868383,300);
  arc(485, 560, 695, 50,0 , PI);
  //bumber painting
  noStroke();
  rect(138,530,695,30);
  stroke(#000000);
    //botton arc 2
  arc(485, 530, 695, 50, -0.3, PI+0.3);
  //botton arc 3
  fill(#14FF00,300);
  arc(485, 520, 663, 50,0 , PI);
  
  //right vertical line
  line(138, 530, 137, 560);
  //left  vertical line
  line(832, 530, 833, 560);
  
  
  //license plate
  strokeWeight(2);
  fill(#BDBFBD,200);
  rect(365,555, 235,29,1);
  
  textSize(20);
  fill(#000000);
  text("O JOGO", 450, 578, 60);
  fill(#08C106,300);
}

void headLights(){

   stroke(#000000);
  //left headlight
  if(headlight==true) fill(#FAA158,25);
  else fill(#FAA158,0);
  noStroke();
  ellipse(256,447, 150,100);
  ellipse(256,447, 300,200);
  ellipse(256,447, 500,400);
  if(headlight==true) fill(#FAA158,190);
  else fill(#9D9A9A,300);
  ellipse(256,447, 25,20);
  stroke(#525252);
  strokeWeight(5);
  ellipse(256,447, 100,63);
  fill(#FFFFFF,100);
  stroke(#FFFFFF,80);
  ellipse(256,447, 80,63);
  ellipse(256,447, 60,43);
  stroke(#000000, 180);

  //right headlight
  if(headlight==true) fill(#FAA158,25);
  else fill(#FAA158,0);
  noStroke();
  ellipse(715,447, 150,100);
  ellipse(715,447, 300,200);
  ellipse(715,447, 500,400);
  if(headlight==true) fill(#FAA158,190);
  else fill(#9D9A9A,300);
  ellipse(715,447, 25,20);
  stroke(#525252);
  strokeWeight(5);
  ellipse(715,447, 100,63);
  fill(#FFFFFF,100);
  stroke(#FFFFFF,50);
  ellipse(715,447, 80,63);
  ellipse(715,447, 60,43);
  
}

void litteHeadlights(){
  //right little headlight
  translate(width/4, height/4);
  rotate(-0.08);
  translate(-width/4, -height/4);
  stroke(#525252);
  strokeWeight(4);
  fill(#A7A6A6,300);
  ellipse(710,560, 47,19);
  if(rArrow == true && ArrowDelay<=10) fill(#FAA158,100);
  else fill(#FFFFFF,100);
  
  stroke(#000000,0);
  ellipse(710,560, 30,15);
  ellipse(710,560, 24,12);
  ellipse(710,560, 13,10);
  ellipse(710,560, 47,19);
  if(rArrow == true && ArrowDelay<=10) fill(#FAA158,25);
  else fill(#FAA158,0);
  ellipse(710,560, 120,50);
  ellipse(710,560, 240,150);

  
  
  //left little headlight
  translate(width/4, height/4);
  rotate(0.16);
  translate(-width/4, -height/4);
  stroke(#525252);
  strokeWeight(4);
  fill(#A7A6A6,300);
  ellipse(263,523, 47,19);
  if(lArrow == true && ArrowDelay<=10) fill(#FAA158,100);
  else fill(#FFFFFF,100);
  stroke(#000000,0);
  ellipse(263,523, 30,15);
  ellipse(263,523, 24,12);
  ellipse(263,523, 13,10);
  ellipse(263,523, 47,19);
  if(lArrow == true && ArrowDelay<=10) fill(#FAA158,25);
  else fill(#FAA158,0);
  ellipse(263,523, 120,50);
  ellipse(263,523, 240,150);
  translate(width/4, height/4);
  rotate(-0.08);
  translate(-width/4, -height/4);

  if(ArrowDelay == 20) ArrowDelay = 0;
  ArrowDelay++;
}

void logo(){
  //logo
  stroke(0);
  fill(#FFFFFF,0);
  noStroke();
  fill(#FFFFFF);
  ellipse(487, 390, 140, 100);
  triangle(412, 440,425, 412,452, 432);
  stroke(#000000);
  line(425, 412, 412, 440);
  line(452, 432, 412, 440);
  arc(487, 390, 140, 100, PI-0.50, TWO_PI+2.1);
  
  //inside the logo
  strokeWeight(1);
  stroke(#45FC4C);
  fill(#45FC4C);
  //arc(487, 390, 110, 77, PI-1, TWO_PI+4);
  ellipse(487, 390,110,77);
  
  
  
  //phone
  strokeWeight(3);
  stroke(#FFFFFF);
  fill(#FFFFFF, 0);
  arc(508, 375, 110, 77, HALF_PI, PI);
  fill(#FFFFFF);
  arc(464, 375, 20, 14, PI+QUARTER_PI-0.8, TWO_PI-1); 
  arc(496, 405, 48, 20, PI+2.6, TWO_PI+1);
  fill(#FFFFFF, 0);
  arc(518, 387, 95, 38, HALF_PI+0.55, PI);
  line(470, 369, 475, 382);
  line(502, 394, 515, 398);
  line(475, 382, 470, 388);
  line(502, 394, 494, 402);
  
  //phone color inside the logo
  strokeWeight(1);
  fill(#FFFFFF);
  circle(505, 405, 15);
  circle(510, 405, 13);
  circle(515, 405, 8.5);
  circle(503, 399, 7);
  circle(509, 400, 7); 
  circle(514, 402, 7);
  circle(505, 400, 7);
  circle(503, 398, 4);
  circle(498, 406, 8.5);
  circle(500, 404, 8.5);
  circle(498, 408, 8.5);
  circle(493, 408, 7.4);
  circle(489, 407, 7.4);
  circle(489, 407, 7.4);
  circle(487, 406, 7.4);
  circle(486, 405, 7.2);
  circle(484, 406, 7);
  circle(484, 406, 7);
  circle(500, 410, 7);
  circle(458, 377, 7);
  circle(462, 377, 7);
  circle(467, 372, 7);
  circle(469, 376, 7);
  circle(469, 378, 7);
  circle(469, 380, 7);
  circle(471, 380, 7);
  circle(464, 380, 7);
  circle(458, 380, 7);
  circle(458, 383, 7);
  circle(462, 383, 7);
  circle(465, 383, 7);
  circle(471, 382, 7);
  circle(465, 385, 7);
  circle(468, 385, 6);
  circle(465, 387, 6);
  circle(462, 387, 6);
  circle(460, 387, 6);
  circle(461, 389, 6);
  circle(462, 389, 6);
  circle(465, 390, 6);
  circle(462, 390, 6);
  circle(464, 393, 6);
  circle(466, 393, 6);
  circle(469, 392, 6);
  circle(469, 396, 6);
  circle(467, 396, 6);
  circle(471, 399, 6);
  circle(474, 398, 6);
  circle(474, 401, 6);
  circle(479, 402, 7);

  strokeWeight(2);
  stroke(255,255,255);
  line(427, 412, 417, 435);
  line(450, 430, 416, 435);
  stroke(#45FC4C);
  fill(#45FC4C);
  triangle(440, 410, 455, 420, 430, 426);
}

void moon(){
  background(#000000);
  strokeWeight(2);
  for(int i = 0; i < 20; i++){
    stroke(#FCFFFC);
    line(posX[i],posY[i]+4,posX[i],posY[i]-4);
    line(posX[i]-4,posY[i],posX[i]+4,posY[i]);
  }
  
  stroke(#000000);
  fill(#A0A0A0);
  ellipse(width/2,600,2500,700);
  
  //holes
  fill(#797C79);
  rotate(-0.05);
  ellipse(100,400,200,80);
  ellipse(50,570,200,80);
  noStroke();
  fill(#484848);
  ellipse(110,417,185,44);
  ellipse(50,581,180,55);
  stroke(#000000);
  fill(#797C79);
  rotate(-0.05);
  ellipse(-10,320,100,40);
  noStroke();
  fill(#484848);
  ellipse(-14,329,90,20);
  
  rotate(0.15);
  stroke(0);
  fill(#797C79);
  ellipse(890,280,200,80);
  ellipse(950,570,200,80);
  noStroke();
  fill(#484848);
  ellipse(890,296,160,47);
  ellipse(950,581,180,55);
  stroke(#000000);
  fill(#797C79);
  rotate(0.05);
  ellipse(1010,320,100,40);
  noStroke();
  fill(#484848);
  ellipse(1014,329,90,20);
  rotate(-0.1);
 
}
void keyPressed(){
  if((key == 'f' || key == 'F') && headlight==false) {
    System.out.println("acendeu o farol");
    headlight = true;
  }
  else if((key == 'f' || key == 'F') && headlight==true) {
    System.out.println("desligou o farol");
    headlight = false;
  }
  
  if((key == 'l' || key == 'L') && wiping == true) {
    wiping = false;
    System.out.println("desligou o limpador");
  }
  else if((key == 'l' || key == 'L') && wiping == false) {
    wiping = true;
   System.out.println("ligou o limpador");
  }
  
  if( keyCode == LEFT && lArrow == false){
    lArrow = true;
    rArrow = false;
    ArrowDelay = 0;
    System.out.println("deu seta pra esquerda");
  }
  else if(keyCode == LEFT && lArrow == true){
    lArrow = false;
    ArrowDelay = 0;
    System.out.println("cancelou a seta pra esquerda");
  }
  
  //arrows
  if( keyCode == RIGHT && rArrow == false){
    lArrow = false;
    rArrow = true;
    ArrowDelay = 0;
    System.out.println("deu seta pra direita");
  }
  else if( keyCode == RIGHT && rArrow == true){
    rArrow = false;
    ArrowDelay = 0;
    System.out.println("cancelou a seta pra direita");
  }
  
  
  //earviewers
  if( (key == 'r' || key == 'R') && earView == false){
    earView = true;
    System.out.println("retraiu o retrovisor");
  }
  else if((key == 'r' || key == 'R') && earView == true){
    earView = false;
    System.out.println("parou de retrair");
  }
  
  //Motor
  if((key == 'm' || key == 'M') && lMotor == false){
    motor.play();
    lMotor = true;
  }
  else if((key == 'm' || key == 'M') && lMotor == true){
    motor.stop();
    lMotor = false;
  }
  
  //Horn
  if((key == 'b' || key == 'B')){
    buzina.play();
  }
  
  // flash alert
  if((key == 'a' || key == 'A') && rArrow == false && lArrow == false){
    rArrow = true;
    lArrow = true;
  }
  
  else if((key == 'a' || key == 'A') && rArrow == true && lArrow == true){
    rArrow = false;
    lArrow = false;
  }
}
