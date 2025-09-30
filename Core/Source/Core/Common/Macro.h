

#define DELETE_COPY_ASSIGNMENT(Class) \
    Class(const Class&) = delete; \
    Class& operator=(const Class&) = delete;


#define SHADER_PATH(Source) "Resources/Shaders/" #Source

#define TEXTURE_PATH(Source) "Resources/Textures/" #Source
