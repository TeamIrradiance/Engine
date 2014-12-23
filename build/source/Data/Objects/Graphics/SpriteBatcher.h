/******************************************************************************/
/*!
\file   SpriteBatcher.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{
  class SpriteMesh;

	class SpriteBatcher
	{
	public:
	  SpriteBatcher ();
	  ~SpriteBatcher ();

    void Initialize ();

    void AddSprite (Sprite* sprite);
    void Batch ();

	private:
    Shader* m_shader;
    Texture* m_texture;
    SpriteMesh* m_mesh;
    VAO* m_vao;
    VBO* m_quadBuffer;
    EBO* m_indexBuffer;
    VBO* m_matrixBuffer;
    VBO* m_texBuffer;

    std::list <Sprite*> m_spriteList;
    bool m_dataReady;
	
	};

}