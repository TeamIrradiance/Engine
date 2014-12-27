/******************************************************************************/
/*!
 \file   ResourceManager.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Template for all proces classes
 */
/******************************************************************************/

#include <Precompiled.h>
#include "Deserialize.h"

namespace Framework
{
  //////////////////////////////////////////////////////////////////////////
  // STATIC VARIABLES
  //////////////////////////////////////////////////////////////////////////
  std::string ResourceManager::RESOURCE_DIRECTORY;
  std::string ResourceManager::SHADER_DIRECTORY;
  std::string ResourceManager::TEXTURE_DIRECTORY;

  std::unordered_map <RESOURCE_TYPE, std::list <Resource*>> ResourceManager::m_resourceMap;


  void ResourceManager::VUpdate(const double dt)
  {

  }

  void ResourceManager::VInit()
  {
#ifdef _WIN32
    RESOURCE_DIRECTORY = "Resources\\";
    SHADER_DIRECTORY = RESOURCE_DIRECTORY + "Shaders\\";
    TEXTURE_DIRECTORY = RESOURCE_DIRECTORY + "Textures\\";
#else
    RESOURCE_DIRECTORY = "Resources/";
    SHADER_DIRECTORY = RESOURCE_DIRECTORY + "Shaders/";
    TEXTURE_DIRECTORY = RESOURCE_DIRECTORY + "Textures/";
#endif // _WIN32

    Load_Resources ();
  }
  
  ResourceManager::ResourceManager()
  {
    std::hash<std::string> id;
    mName = std::string("resources");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager
    
  }

  ResourceManager:: ~ResourceManager()
  {
    for (auto& i : m_resourceMap [R_SHADER])
    {
      delete i;
    }
    for (auto& i : m_resourceMap [R_TEXTURE])
    {
      delete i;
    }
  }

  Resource* ResourceManager::LoadResource(std::string resourceName, unsigned resourceType)
  {
    for (auto& i : m_resourceMap [(RESOURCE_TYPE)resourceType])
    {
      if (i->Name == resourceName)
      {
        return i;
      }
    }

    return nullptr;
  }

  //////////////////////////////////////////////////////////////////////////
  // PRIVATE METHODS
  //////////////////////////////////////////////////////////////////////////

  void ResourceManager::Load_Resources ()
  {
    Load_Shaders ();
    Load_Textures ();
  }
  using namespace std;
  void find_and_replace (string& source, string const& find, string const& replace)
  {
    for (std::string::size_type i = 0; (i = source.find (find, i)) != std::string::npos;)
    {
      source.replace (i, find.length (), replace);
      i += replace.length () - find.length ();
    }
  }

  void getFilesList (std::string filePath, std::string extension, std::vector<std::string>& f)
  {
    std::string fullPath = filePath;
    FILE* pipe = NULL;
    string pCmd = "dir /B /S " + fullPath;
    char buf [256];

    if (NULL == (pipe = _popen (pCmd.c_str (), "rt")))
    {
      cout << "Shit" << endl;
      return;
    }

    while (!feof (pipe))
    {
      if (fgets (buf, 256, pipe) != NULL)
      {
        std::string s = buf;
        char fp [256] = "";
        DWORD retval;
        retval = GetFullPathName ("Hello.txt", 256, fp, nullptr);
        std::string fullPath = fp;
        fullPath.replace (fullPath.find ("Hello"), fullPath.length (), "");
        s.replace (s.find(fullPath), fullPath.length (), "");
        find_and_replace (s, "\n", "");

        if (s.find (extension) != string::npos)
        {
          f.push_back (s);
        }
      }

    }

    _pclose (pipe);
  }

  void ResourceManager::Load_Shaders ()
  {
    // List of Vertex Shaders, Fragment Shaders, Shader Programs
    std::vector <std::string> VERTEX;
    std::vector <std::string> FRAG;

    getFilesList (SHADER_DIRECTORY, ".vs.glsl", VERTEX);
    getFilesList (SHADER_DIRECTORY, "fs.glsl", FRAG);

    std::ifstream shaderComposition (SHADER_DIRECTORY + "Shaders.txt");

    if (!shaderComposition.good ())
    {
      std::cout << "Failed to load Shader File..." << "Shaders.txt\n";
    }
    else
    {
      std::string data;
      Shader* shader = new Shader ();
      std::unordered_map <std::string, GLuint> vSource;
      std::unordered_map <std::string, GLuint> fSource;
      std::unordered_map <std::string, GLuint> gSource;

      std::cout << "--------------------------------\nCompiling Shaders...\n";

      for (auto& vsFile : VERTEX)
      {
        std::ifstream ifile (vsFile);
        // Compile All Vertex Shaders
        vSource [vsFile] = shader->Compile_Shader ((vsFile).c_str (), shader->Read_Shader ((vsFile).c_str ()).c_str (), GL_VERTEX_SHADER);
      }

      for (auto& fsFile : FRAG)
      {
        // Compile All Fragment Shaders
        fSource [fsFile] = shader->Compile_Shader ((fsFile).c_str (), shader->Read_Shader ((fsFile).c_str ()).c_str (), GL_FRAGMENT_SHADER);
      }

      while (!shaderComposition.eof ())
      {
        std::string vs, fs, gs, name;
        shaderComposition >> name; name = "";
        shaderComposition >> vs;
        shaderComposition >> fs;
        shaderComposition >> gs;
        shaderComposition >> name;
        if (gs == "0")
        {
          // Link The Corresponding Vertex And Fragment Shaders in the Shader Program File
          shader->m_program = shader->Link_Program (name.c_str(), vSource [SHADER_DIRECTORY + vs], fSource [SHADER_DIRECTORY + fs]);
          m_resourceMap [R_SHADER].push_back (shader);
        }
        else
        {
          // Link The Corresponding Vertex And Fragment Shaders in the Shader Program File
          shader->m_program = shader->Link_Program (name.c_str(), vSource [vs], fSource [fs], gSource [gs]);
          m_resourceMap [R_SHADER].push_back (shader);
        }
      }
    }
  }

  void ResourceManager::Load_Textures ()
  {
    std::vector <std::string> TEXTURE;
    getFilesList (TEXTURE_DIRECTORY + "ATLAS\\", ".png", TEXTURE);

    for (auto& i : TEXTURE)
    {
      std::string name = i;
      name.replace (name.find (TEXTURE_DIRECTORY + "ATLAS\\"), std::string(TEXTURE_DIRECTORY + "ATLAS\\").length(), "");
      name.replace (name.find (".png"), name.length (), "");
      Texture* texture = new Texture ();
      texture->Load_Texture (name.c_str(), i.c_str());
      m_resourceMap [R_ATLAS].push_back (texture);
    }

    TEXTURE.clear ();
    getFilesList (TEXTURE_DIRECTORY + "PNG\\", ".png.meta", TEXTURE);
    for (auto& i : TEXTURE)
    {
      std::string name = i;
      name.replace (name.find (TEXTURE_DIRECTORY), TEXTURE_DIRECTORY.length(), "");
      Texture* texture = new Texture ();

      std::ifstream in (i);
      ErrorIf (!in.is_open (), "%s is not found");
      std::stringstream sstr;
      sstr << in.rdbuf ();

      Json::Value& root = Json::Value ();   // will contains the root value after parsing.
      Json::Reader reader;
      bool parsingSuccessful = reader.parse (sstr.str (), root);
      ErrorIf (!parsingSuccessful, "json parsing failed, check opened json file's formating");
      Json::Value& curRoot = root ["Texture"];
      std::cout << root;
      DeserializeData (texture, &curRoot);
      texture->Set (static_cast<Texture*> (LoadResource (texture->AtlasName, R_ATLAS)));
      m_resourceMap [R_TEXTURE].push_back (texture);
    }

    static_cast<Texture*> (LoadResource ("ATLAS", R_ATLAS))->Bind ();
  }

}