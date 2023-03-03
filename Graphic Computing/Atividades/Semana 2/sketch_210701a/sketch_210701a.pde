void setup()
{
  size(800, 650);
  strokeWeight(2.5);
  background(201, 201, 201);
}

void draw()
{
  // PREDIO
  stroke(255);
  fill(250, 0, 0);
  rect(150, 150, 370, 440);
  
  // TETO
  stroke(0, 0, 255);
  fill(0, 0, 255);
  triangle(156, 150, 517, 150, 380, 60);
  
  // JANELAS
  stroke(0, 0, 0);
  fill(0, 0, 0);
  rect(200, 180, 100, 50);
  
  stroke(0, 0, 0);
  fill(0, 0, 0);
  rect(200, 260, 100, 50);
  
  stroke(0, 0, 0); 
  fill(0, 255, 0);
  rect(200, 430, 100, 50);
  
  stroke(0, 0, 0);
  fill(0, 255, 0);
  rect(200, 345, 100, 50);
  
  stroke(0, 0, 0);
  fill(8, 90, 0);
  rect(380, 180, 100, 50);
  
  stroke(0, 0, 0);
  fill(8, 90, 0);
  rect(380, 260, 100, 50);
  
  line(250, 346, 250, 394);
  line(250, 432, 250, 478);
  
  line(430, 182, 430, 230);
  line(430, 261, 430, 310);
  
  // PORTA
  stroke(0, 0, 0);
  fill(0, 255, 0);
  rect(380, 467, 100, 120);
  line(430, 468, 430, 585);
  
  // CHAO
  stroke(95, 62, 7);
  fill(95, 62, 7);
  rect(0, 590, 800,  100);
  
  // ARVORE
  stroke(0, 0, 0);
  fill(57, 35, 0);
  rect(650, 400, 20,  190);
  fill(0, 255, 0);
  ellipse(660, 290, 60, 250);
  
  save("teste.png");
}
