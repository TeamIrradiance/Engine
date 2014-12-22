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

namespace Framework
{
  //////////////////////////////////////////////////////////////////////////
  // STATIC VARIABLES
  //////////////////////////////////////////////////////////////////////////
  std::string ResourceManager::RESOURCE_DIRECTORY;
  std::string ResourceManager::SHADER_DIRECTORY;
  std::string ResourceManager::TEXTURE_DIRECTORY;

  std::unordered_map <RESOURCE_TYPE, std::unordered_map <std::string, Resource*>> ResourceManager::m_resourceMap;


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
      delete i.second;
    }
  }

  Resource* ResourceManager::LoadResource(std::string resourceName, unsigned resourceType)
  {
    for (auto& i : m_resourceMap [(RESOURCE_TYPE)resourceType])
    {
      if (i.first == resourceName)
      {
        return i.second;
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
          m_resourceMap [R_SHADER][name] = static_cast <Resource*> (shader);
        }
        else
        {
          // Link The Corresponding Vertex And Fragment Shaders in the Shader Program File
          shader->m_program = shader->Link_Program (name.c_str(), vSource [vs], fSource [fs], gSource [gs]);
          m_resourceMap [R_SHADER][name] = static_cast<Resource*> (shader);
        }
      }
    }
  }

}