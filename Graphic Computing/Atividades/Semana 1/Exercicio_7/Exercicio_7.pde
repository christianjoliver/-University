void setup()
{
  size(500, 500);  
}

void draw()
{
  background(255, 255, 255);
  
  fill(255, 0, 243, 40);
  ellipse(80, 30, 20, 20);
  
  fill(255, 0, 243, 70);
  ellipse(100, 60, 40, 40);
  
  fill(255, 0, 243, 120);
  ellipse(130, 140, 80, 80);
  
  translate(50, 250);
  fill(255, 0, 255);
  stroke(255, 0, 0);
  ellipse(0, 0, 100, 100);
  
  save("teste.png");
}
