#pragma once

class Triangle
{
private:
	unsigned int _VAO, _VBO;
public:
	Triangle(float vertices[9]);
	~Triangle();

	void Draw();
};

Triangle::Triangle(float vertices[9])
{

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);

	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, 36, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

Triangle::~Triangle() 
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
}

void Triangle::Draw()
{
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}