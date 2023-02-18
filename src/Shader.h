//
// Created by David Goldring on 2023-02-03.
//

#ifndef YAMC_SHADER_H
#define YAMC_SHADER_H

#include <string>
#include "GL/glew.h"

class Shader {
public:
    Shader();
    ~Shader();

    bool Load(const std::string& vertName, const std::string& fragName);
    void SetActive();

private:
    bool CompileShader(const std::string& filename, GLenum shaderType, GLuint& outShader);
    bool IsCompiled(GLuint shader);
    bool IsValidProgram();

    GLuint vertexShader_ {};
    GLuint fragmentShader_ {};
    GLuint shaderProgram_ {};
};


#endif //YAMC_SHADER_H
