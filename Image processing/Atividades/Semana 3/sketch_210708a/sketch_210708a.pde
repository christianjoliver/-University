PImage picture;

void setup()
{
  size(392, 369);
  picture = loadImage("pimba.jpg");
  
  loadPixels();
  picture.loadPixels();
  //background(0, 0, 0);
  int a = picture.height;
  int l = picture.width;
  for(int y = 0; y < a; y++)
  {
    for(int x = 0; x < l; x++)
    {
     int loc = x + y*l;
     float r = red(picture.pixels[loc]);
     float g = green(picture.pixels[loc]);
     float b = blue(picture.pixels[loc]);
     
     pixels[loc] = color(255 - r, 255 - g, 255 - b);
     
    }
  }
  updatePixels();
  save("teste.png");
}
