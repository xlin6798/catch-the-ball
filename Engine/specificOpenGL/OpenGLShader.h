#pragma once
#include "ShaderImplementation.h"

namespace Engine
{
    class OpenGLShader : public ShaderImplementation
    {
    public:
        OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
        virtual void Bind() override;
        virtual void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3) override;
        virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;

    private:
        unsigned int mShaderProgram;
    };
}

