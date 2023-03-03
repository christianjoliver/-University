void setup()
{
  size(500, 500);  
}

void draw()
{
  background(255, 255, 255);
  translate(50, 250);
  fill(255, 0, 255);
  stroke(255, 0, 0);
  ellipse(0, 0, 100, 100);
  fill(255, 0, 243, 120);
  ellipse(130, 0, 100, 100);
  fill(255, 0, 243, 70);
  ellipse(265, 0, 100, 100);
  fill(255, 0, 243, 40);
  ellipse(400, 0, 100, 100);
  save("teste.png");
}
