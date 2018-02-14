//
//  internal-logger.h
//  Residue C++
//
//  Official C++ client library for Residue logging server
//
//  Copyright (C) 2017-present Muflihun Labs
//  Copyright (C) 2017-present @abumusamq
//
//  https://muflihun.com/
//  https://muflihun.github.io/residue/
//  https://github.com/muflihun/residue-cpp/
//
//  See https://github.com/muflihun/residue-cpp/blob/master/LICENSE
//  for licensing information
//

#ifndef RESIDUE_INTERNAL_LOGGER_H
#define RESIDUE_INTERNAL_LOGGER_H

#include <sstream>
#include "include/residue.h"
///
/// \brief Internal logging class. We do not use Easylogging++ macros here
/// for they will cause issue when dispatching
///
class InternalLogger
{
public:
    enum Level {
        crazy,   // 0
        debug,   // 1
        info,    // 2
        warning, // 3
        error,   // 4
        none     // 5
    };

    explicit InternalLogger(Level level)
        : m_level(level),
          m_enabled(level >= Residue::s_internalLoggingLevel)
    {
    }

    template <typename T>
    InternalLogger& operator<<(const T& item)
    {
        if (m_enabled) {
            m_stream << item;
        }
        return *this;
    }

    virtual ~InternalLogger();
private:
    std::stringstream m_stream;
    Level m_level;
    bool m_enabled;
};

#endif /* RESIDUE_INTERNAL_LOGGER_H */