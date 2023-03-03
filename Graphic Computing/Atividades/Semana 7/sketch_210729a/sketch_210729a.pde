PImage picture;
PImage  aux = createImage(500, 296, RGB);

void setup()
{
  size(500, 296);
  picture = loadImage("pimba.jpg");
  picture.loadPixels();
  aux.loadPixels();
  
  float ang = 57;
  int a = picture.height;
  int l = picture.width;
  
  for(int y = 0; y < a; y++)
  {
    for(int x = 0; x < l; x++)
    {
       int loc = x + (y*l);
       
       int xl = (int)(x*cos(ang) - y*sin(ang));
       int yl = (int)(x*sin(ang) + y*cos(ang));
       
       int loc2 = xl+ (yl*l);
       
       if(loc2 >= 0 && loc2 < l * a){
         aux.pixels[loc2] = picture.pixels[loc];
       }
    }
  }
  picture.resize(0, 735);
  
}

void draw(){
  image(aux, 0, 0);
}
