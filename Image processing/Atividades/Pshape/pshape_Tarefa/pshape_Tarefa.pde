PShape square;

float rot;
float rotY;
float rotZ;
float speedCam;
float t3;
float t4;
boolean orthographic = false;

void setup(){
    size(1000, 800, P3D);
    rot = HALF_PI/2;
    t4 = 0;
}

void draw(){
  background(#343434);
  textSize(14);
  fill(#FFFFFF);
  text("Botões do Mouse - Eixo X: Rotação da Câmera; Eixo Y: Altura da Câmera", 10, 30);
  text("Scroll do Mouse - Distância de perspectiva", 10, 50);
  text("Letra o/O - Alterar Projeção (Perspectiva/Ortográfica)", 10, 70);
  ambientLight(80, 100, 110);
  directionalLight(255, 255, 126, 1, 1, 0);
  ortho();
  translate(width/2+30, height/2+50, 100+t3/7);
  speedCam = TWO_PI/width;
  rotateZ(HALF_PI);
  rotateY(-HALF_PI);
  
  if(orthographic) ortho();
  else perspective();
  
  if(mousePressed){
    rot+= (pmouseX - mouseX) * speedCam;
    rotate(rot);
    t4 += (pmouseY - mouseY)/2;
    translate(0, 0, -t4);   
  }
  
  else{
    rotate(rot);
    translate(0, 0, -t4);  
  }
  
  beginShape(TRIANGLES);
    fill(180, 0, 0);
    vertex(-100, -100, -100);
    vertex( 100, -100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, -100, -100);
    vertex( 100,  100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, 100, -100);
    vertex(-100, 100, -100);
    vertex(   0,   0,  100);
    
    vertex(-100,  100, -100);
    vertex(-100, -100, -100);
    vertex(   0,    0,  100);
  endShape(CLOSE);
  
  scale(0.8);
  translate(0, 300, -30);
  beginShape(TRIANGLES);
    fill(#005FD1);
    vertex(-100, -100, -100);
    vertex( 100, -100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, -100, -100);
    vertex( 100,  100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, 100, -100);
    vertex(-100, 100, -100);
    vertex(   0,   0,  100);
    
    vertex(-100,  100, -100);
    vertex(-100, -100, -100);
    vertex(   0,    0,  100);
  endShape(CLOSE);
  
  
  scale(0.8);
  translate(0, -700, -20);
  beginShape(TRIANGLES);
    fill(#00D128);
    vertex(-100, -100, -100);
    vertex( 100, -100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, -100, -100);
    vertex( 100,  100, -100);
    vertex(   0,    0,  100);
    
    vertex( 100, 100, -100);
    vertex(-100, 100, -100);
    vertex(   0,   0,  100);
    
    vertex(-100,  100, -100);
    vertex(-100, -100, -100);
    vertex(   0,    0,  100);
  endShape(CLOSE);  
}

void keyPressed(){
  if((key == 'o' || key == 'O') && orthographic == true) orthographic = false;
  else if((key == 'o' || key == 'O') && orthographic == false) orthographic = true;
}
void mouseWheel(MouseEvent event){
  t3 += event.getCount()*50;
}
