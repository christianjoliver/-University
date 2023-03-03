void setup()
{
  size(500, 500);  
}

void draw()
{
  background(255, 255, 255);
  ellipse(80, 80, 100, 100);
  ellipse(400, 400, 150, 100);
  line(0, 0, 500, 500);
  translate(200, 200);
  rect(0, 0, 80, 80);
  save("teste.png");
}
