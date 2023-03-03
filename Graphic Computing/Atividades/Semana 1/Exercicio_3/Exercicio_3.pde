void setup()
{
  size(500, 500);  
}

void draw()
{
  stroke(255, 0, 243);
  background(255, 255, 255);
  fill(255, 0, 0);
  ellipse(80, 80, 100, 100);
 
  fill(0, 0, 255);
  ellipse(400, 400, 150, 100);
 
  line(0, 0, 500, 500);
  
  translate(200, 200);
  fill(0, 255, 0);
  rect(0, 0, 80, 80);
  
  save("teste.png");
}
