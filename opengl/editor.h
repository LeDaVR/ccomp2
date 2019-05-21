#ifndef EDITOR_H
#define EDITOR_H

#include "dinamicarray.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_m.h>

#include "camera.h"



class Editor{
	private:
		int dimension;
		int basic;
		float cuadrante;
		bool **matrix;
		DinamicArray<float> vertices;
		DinamicArray<unsigned int> indices;
		DinamicArray<unsigned int> select;
		DinamicArray<unsigned int> objects;
	public:
		Editor();
		
		bool isinside(GLFWwindow* window,Camera* camara);
		void use(GLFWwindow* window,Camera* camara);		
		
		
		int getVerticesSize();
		int getIndicesSize();
		float* getVerticesArray();
		unsigned int* getIndicesArray();

		~Editor();
	
};


#endif
