// QtrBkLib.h - Contains declaration of Korabe library functions
#pragma once
using namespace System;

#ifdef QTRBKLIB_EXPORTS
#define QTRBKLIB_API __declspec(dllexport)
#else
#define QTRBKLIB_API __declspec(dllimport)
#endif // QTRBKLIB_EXPORTS

extern "C" QTRBKLIB_API struct qtrbk
{
	const char * request;
	const char * response;
	const char * error;
	int err;
};

extern "C" QTRBKLIB_API void process_request(struct qtrbk * qb);

extern "C" QTRBKLIB_API struct qtrbk* create_qtrbk(const char * xml);

const char * responseToChars(String ^ ressponse);

void ProcessRequest(struct qtrbk * qb);