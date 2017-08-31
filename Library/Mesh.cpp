#include "DXUT.h"
#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	Texture->Release();
	XMesh->Release();
}
