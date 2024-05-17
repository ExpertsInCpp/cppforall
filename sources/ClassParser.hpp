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
        Success,      //! The file was processed without any errors
        FileNotFound, //! The file wasn't found
    };

public:

    ClassParser() = default;
    virtual ~ClassParser() = default;

    Error ParseString( const std::wstring &content, Class &output );
    Error ParseFile( const std::wstring &path, Class &output );
    Error GetLastError( int *nLine = nullptr );

    static std::wstring GetErrorDescription( Error error );

protected:

    std::tuple<Error, int> m_tLastError = { Error::Success, 0 };
    Error ReadFile( const std::wstring &path, std::wstring &content );
    Error ParseLine( const std::string &line );

};
