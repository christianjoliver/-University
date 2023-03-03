/*
  
  Aluno: Christian Jonas Oliveira
  Acoes: Acender/Apagar luzes - Botao esquerdo do mouse
         Mudar cor da Arvore - Botao direito do mouse
         Trocar cor do predio e teto - passar mouse em cima
*/


boolean i = false;
boolean j = false;
void setup()
{
  size(800, 650);
  strokeWeight(2.5);
  background(201, 201, 201);
  
}

void draw()
{

  frameRate(12);
  // PREDIO
  
  if((mouseX > 150 && mouseX < 520) && (mouseY >150 && mouseY < 590))
  {
    stroke(255);
    fill(#E608FF);
    rect(150, 150, 370, 440);
  }
  else
  {
    stroke(255);
    fill(250, 0, 0);
    rect(150, 150, 370, 440);
  }
  
  // TETO
  
  if((mouseX > 156 && mouseX < 517) && (mouseY > 60 && mouseY < 150)){
    stroke(#E608FF);
    fill(#E608FF);
    triangle(156, 150, 517, 150, 380, 60);
  }
  else
  {
    stroke(0, 0, 255);
    fill(0, 0, 255);
    triangle(156, 150, 517, 150, 380, 60);
  }
  
  
  // JANELAS
  if(i==false && mouseButton==LEFT && mousePressed==true) i = true;
  else if(i==true && mouseButton==LEFT && mousePressed==true) i = false;
  
  if(i==false){
    stroke(0, 0, 0);
    fill(8, 90, 0);
  }
  else
  {
    stroke(0, 0, 0);
    fill(#DECC09);
  }
  rect(200, 180, 100, 50);
  line(250, 182, 250, 230);
  
  rect(200, 260, 100, 50);
  line(250, 262, 250, 310);
  
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
  stroke(95, 62, 7);
  fill(95, 62, 7);
  rect(0, 590, 800,  100);
  
  
  // ARVORE
  if(j==false && mouseButton==RIGHT && mousePressed==true) j = true;
  else if(j==true && mouseButton==RIGHT && mousePressed==true) j = false;
  
  fill(57, 35, 0);
  rect(650, 400, 20,  190);
  if(j==false){
    fill(0, 255, 0);
  }
  else
  {
    fill(#C6B810);
  }
  stroke(0, 0, 0);
  ellipse(660, 290, 60, 250);
  
  saveFrame("line - ######.png");
}
