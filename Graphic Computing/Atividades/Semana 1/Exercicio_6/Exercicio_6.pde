PImage picture;
void setup()
{
  size(500, 500);
  picture = loadImage("pimba.jpg");
}

void draw()
{
  background(0, 0, 0);
  image(picture, 10, 10, 180, 180);
  image(picture, 200, 200, 100, 300);
  save("teste.png");
}
