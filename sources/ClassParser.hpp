#pragma once

/**
 * Is in charge of parsing .cppfall files into the intermediate format Class.
 * Then Class may be passed to different generators to create different interfaces.
 */
class ClassParser
{

public:

    enum class Error
    {
        Success,
        FileNotFound,
    };

public:

    ClassParser() = default;
    virtual ~ClassParser() = default;

    Error ParseString( const std::string &content, Class &output );
    Error ParseFile( const std::wstring &path, Class &output );
    Error GetLastError( int *nLine = nullptr, int *nColumn = nullptr );

protected:

    Error ParseLine( const std::string &line, Class &output );
    std::tuple<Error, int, int> m_tLastError = { Error::Success, 0, 0 };

};
