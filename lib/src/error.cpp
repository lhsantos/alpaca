#include "error.h"
#include <sstream>

namespace alpaca
{
    exception::exception(
        const std::string& msg,
        const inner_ptr_t& inner,
        const char* const func,
        const char* const file,
        int line
    ) noexcept
        : m_msg(msg), m_inner(inner), m_function(func), m_file(file), m_line(line) {}

    exception::exception(
        const std::string& msg,
        const exception& inner,
        const char* const func,
        const char* const file,
        int line
    ) noexcept
        : exception(msg, inner_ptr_t(new exception(inner)), func, file, line) {}

    exception::exception(
        const char* const func,
        const char* const file,
        int line
    ) noexcept
        : exception("", inner_ptr_t(nullptr), func, file, line) {}
    
    const exception& exception::operator<<(const exception& other)
    {
        other.m_function = m_function;
        other.m_file = m_file;
        other.m_line = m_line;
        return other;
    }

    const char* exception::what() const noexcept
    {
        return m_msg.c_str();
    }

    std::string exception::to_str() const
    {
        std::ostringstream out;
        to_str(out);
        return out.str();
    }

    void exception::to_str(std::ostream& out) const
    {
        out << m_file
            << ":" << m_line
            << ":" << m_function
            << ": " << m_msg;
    }
    
    void exception::trace(std::ostream& out) const
    {
        to_str(out);
        const exception* next = this;
        while ((next = next->m_inner.get()))
        {
            out << " caused by" << std::endl;
            next->to_str(out);
        }
        out << std::endl;
    }

    exception::exception(const exception&) = default;
    exception::exception(exception&&) = default;
    exception& exception::operator=(const exception&) = default;
    exception& exception::operator=(exception&&) = default;
    exception::~exception() = default;
}
