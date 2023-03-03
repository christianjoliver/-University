 /*
  
 Aluno: Christian Jonas Oliveira
 Acoes: Mover o mouse gera um evento de luz naquela direcao
 
 */


void setup()
{
  size(800, 650, P3D);
  strokeWeight(2.5);
  background(#262D3B);
}

void draw()
{

  // LUZES
  
  ambientLight(100, 100, 100);
  spotLight(255, 255, 255, mouseX, mouseY, 2000, 0, 0, -1, 2, 10000);
  pointLight(51, 255, 255, mouseX, mouseY, 200);
  directionalLight(51, 102, 126, 1, 0, 0);
  
  directionalLight(100,100,100,width/2,height/2,-mouseY);
  pointLight(50,50,100,width/2,height/2,-mouseX);
  
  
  // PREDIO
  noStroke();
  fill(250, 0, 0);
  rect(150, 150, 370, 440);
  
  // TETO 
  noStroke();
  fill(0, 0, 255);
  triangle(156, 150, 517, 150, 380, 60);

  // JANELAS APAGADAS
  stroke(0, 0, 0);
  fill(#171717);

  rect(200, 180, 100, 50);
  line(250, 182, 250, 230);

  rect(200, 260, 100, 50);
  line(250, 262, 250, 310);

  // JANELAS ACESAS
  stroke(0, 0, 0);
  fill(8, 90, 0);

  rect(200, 430, 100, 50);
  line(250, 432, 250, 478);

  rect(200, 345, 100, 50);
  line(250, 346, 250, 394);

  rect(380, 180, 100, 50);
  line(430, 182, 430, 230);

  rect(380, 260, 100, 50);
  line(430, 261, 430, 310);

  rect(380, 345, 100, 50);
  line(430, 347, 430, 394);

  // PORTA
  stroke(0, 0, 0);
  fill(0, 255, 0);
  rect(380, 467, 100, 120);
  line(430, 468, 430, 585);

  // CHAO
  noStroke();
  fill(95, 62, 7);
  rect(0, 590, 800, 100);

  // ARVORE
  fill(57, 35, 0);
  noStroke();
  rect(650, 400, 20, 190);
  fill(8, 90, 0);
  noStroke();
  
  translate(660, 300);
  sphere(100);
}
