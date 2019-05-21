#include "editor.h"
Editor::Editor(){
	dimension=40;
	cuadrante=0.1f;
	for(int i=0;i<=dimension;i++){
		for(int j=0;j<=dimension;j++){
			vertices.push_back(float(j)*cuadrante);
			vertices.push_back(float(i)*cuadrante);
			vertices.push_back(0.0f);
		}
	}
	
	int cont=0;
	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
			indices.push_back(cont);
			indices.push_back(cont+1);
			indices.push_back(cont+dimension+2);
			indices.push_back(cont+dimension+1);
			indices.push_back(cont);	
			cont++;
		}
		indices.push_back(cont+dimension);
		cont++;
	}
}

bool Editor::isinside(GLFWwindow* window,Camera* camara){
	double xpos,ypos;
	xpos=camara->get3dposX(window);
	ypos=camara->get3dposY(window);
	if(xpos>=0&&xpos<=dimension*cuadrante&&ypos>=0&&ypos<=dimension*cuadrante)
		return true;
	return false;
}

void Editor::use(GLFWwindow* window,Camera* camara){
	glDrawElements(GL_TRIANGLES,objects.getSize(),GL_UNSIGNED_INT,objects.arr);
	select.clear();
	if(!(isinside(window,camara)))
		return;
	double xpos,ypos;
	xpos=camara->get3dposX(window);
	ypos=camara->get3dposY(window);
	int indexdraw=int(xpos/cuadrante)+((int(ypos/cuadrante)+1)*(dimension+1));
	select.push_back(indexdraw);
	select.push_back(indexdraw+1);
	select.push_back(indexdraw-dimension);
	select.push_back(indexdraw);
	select.push_back(indexdraw-dimension-1);
	select.push_back(indexdraw-dimension);
	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	if(state == GLFW_PRESS){
		objects.addArray(&select);
	}
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,select.arr);
}

int Editor::getVerticesSize(){
	return vertices.getSize();
}

int Editor::getIndicesSize(){
	return indices.getSize();
}

float* Editor::getVerticesArray(){
	return vertices.arr;
}
unsigned int* Editor::getIndicesArray(){
	return indices.arr;
}

Editor::~Editor(){
}

