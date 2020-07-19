# Korabe QtrBk (pronounced Quarterback)

## Synopsis

Despite the QuickBooks SDK, connection to QuickBooks from a web application has been notoriously difficult. Here are some reasons why:

1. Using common web application languages such as PHP, Javascript, Ruby, Python, there has been no easy way to connect directly to QuickBooks. 
1. The QuickBooks remote connector relies on a queueing system

Quarterback solves this problem for languages with a [foreign function interface](https://en.wikipedia.org/wiki/Foreign_function_interface). Quarterback is a library that exports functions that can then be accessed through the language's forign function interface.

### Build

As of yet there are no special build instructions.

```bash
cl /Yu"pch.h" /GS /analyze- /W3 /Zc:wchar_t /Zi /Od /Fd"Debug\vc141.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_WINDLL" /D "_UNICODE" /D "UNICODE" /D "QTRBKLIB_EXPORTS" /errorReport:prompt /WX- /Zc:forScope /Oy- /clr /FU"C:\Windows\Microsoft.NET\assembly\GAC_MSIL\Interop.QBXMLRP2\v4.0_27.0.151.3006__8244b228ecdaef5e\Interop.QBXMLRP2.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.7.1\mscorlib.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.7.1\System.Data.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.7.1\System.dll" /FU"C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.7.1\System.Xml.dll" /MDd /FC /Fa"Debug\" /EHa /nologo /Fo"Debug\" /Fp"Debug\QtrBkLib.pch" /diagnostics:classic 
```

### Configure

To make the QtrBk.dll library available to your PHP web application, the dll path must be accessible through the `PATH` environment variable.

### Components of a QuickBooks request via QtrBk

#### QtrBk.Request

The request is comprised of XML, and QBXML to be more exact. 