float fov;
float cameraZ;
float rotX;
float rotY;
float speedCam;
float t3;

void setup(){
  size(1080, 720, P3D);
  fill(204);
  fov = PI/2.8;
  cameraZ = (height/2.0) / tan(fov/2.0);
  rotX = -PI/6;
  rotY = PI/3;
  t3 = 0;
  
}

void draw(){
  background(0);
  lights();
  
  translate(width/2, height/2, t3);
  
  speedCam = TWO_PI/width;
  if(mousePressed){
    rotX+= (pmouseY - mouseY) * speedCam;
    rotY+= (pmouseX - mouseX) * speedCam;
    
    rotateX(rotX);
    rotateY(rotY);
  }
  
  else{
    rotateX(rotX);
    rotateY(rotY);
  }
 
  //perspective();
  
  
  fill(#5DCAFF);
  box(160);
  
  translate(0, 0, -300);
  fill(#C6707A);
  //ortho();
  sphere(100);
  
  //perspective();
  fill(#9BFC96);
  translate(-500, 500, -500);
  box(160);
  
  square(0, 0, 300);
}

void mouseWheel(MouseEvent event){
  t3 += event.getCount()*50;
}
