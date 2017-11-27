#pragma once

#include <iosfwd>
#include <string_view>
#include <vector>

enum class ShaderType {vertex, fragment};
class Shader {
public:
    Shader(ShaderType type, std::ifstream&& file);
    Shader(ShaderType type, const std::string_view& source);
    Shader(Shader&& rhs);
    Shader& operator = (Shader&& rhs);

    Shader(const Shader&) = delete;
    Shader& operator = (const Shader&) = delete;

    ~Shader();

private:
    friend class Program;

    operator unsigned() const noexcept
    {
        return m_shader;
    }

private:
    ShaderType m_type;
    unsigned m_shader;
};

class Program {
public:
    Program(std::vector<Shader>&& shaders);
    Program(const Program&) = delete;
    Program(Program&& rhs);

    Program& operator = (const Program&) = delete;
    Program& operator = (Program&& rhs);

    ~Program();

    void enable();
    void disable();

private:
    void link();
    void validate();

protected:
    unsigned m_program;

private:
    std::vector<Shader> m_shaders;
};
