#include <iostream>
#include <ctime>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "SOIL.h"
#include "skilLib.h"
#include "systems.h"
#include "components.h"

int windowheight = 422;
int windowwidth = 716;
std::string title = "RTS-CTF-CONCEPT";
double libVersion = 0.1;


GLFWwindow* window;
/*
void GLFWCALL windowResize(int getwidth, int getheight){
    windowheight=getheight;
    windowwidth=getwidth;
}
*/


Engine *theEngine;

Registry* getRegistry(){
  return &(theEngine->registry);
}

void buildRegistry(){

  /*
  float xMaps[4] = {0.0, 1.0, 1.0, 0.0};
  float yMaps[4] = {0.0, 0.0, 1.0, 1.0};

  theEngine->registry.addTextureMapped("default", "default", xMaps, yMaps);
  */
  theEngine->loadXUPL("res/stockComponents.xupl");
  theEngine->loadXUPL("res/stockResources.xupl");



  theEngine->registry.Register(new Color(), "color");
  theEngine->registry.Register(new Position(), "position");
  theEngine->registry.Register(new Dimensions(), "dimensions");  
  theEngine->registry.Register(new Vector(), "vector");
  theEngine->registry.Register(new Texture(), "texture");

  theEngine->registry.dump();
 
}

int main(){  
  std::cout<<"Loaded SkilLib v" << libVersion << "\n";
  theEngine = new Engine();
  theEngine->addSystem(new WindowSystem(windowwidth, windowheight, "RTS-CTF CONCEPT"));
  theEngine->addSystem(new TimekeeperSystem());
  theEngine->addSystem(new MovementSystem());
  theEngine->addSystem(new RenderSystem());
    
  buildRegistry();
	

  Entity* tmp = new Entity();
  
  tmp->addComponent(theEngine->registry.getComponent("texture monospaceWhite3"));
  tmp->addComponent(theEngine->registry.getComponent("dimensions 32 32"));
  tmp->addComponent(theEngine->registry.getComponent("position 0 128"));
  //tmp->addComponent(theEngine->registry.getComponent("vector 300.0 1.0 " + std::to_string(COMPONENT_VELOCITY)));
  //tmp->addComponent(theEngine->registry.getComponent("vector 100.0 4.7 " + std::to_string(COMPONENT_ACCELERATION)));
  theEngine-> addEntity(tmp);

  theEngine->start();
    
}

