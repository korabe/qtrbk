#include "pch.h"
#include "QtrBkLib.h"
#include < stdlib.h >
#include < vcclr.h >

using namespace Interop::QBXMLRP2;

QTRBKLIB_API void process_request(qtrbk * qb)
{
	ProcessRequest(qb);
}

QTRBKLIB_API qtrbk * create_qtrbk(const char * xml)
{
	qtrbk * request =  new qtrbk;
	request->request = xml;
	request->err = 0;
	return request;
}

void ProcessRequest(qtrbk * qb)
{
	String ^ request = gcnew String(qb->request);

	String^ ticket;
	String^ response;
	Interop::QBXMLRP2::IRequestProcessor6^ rqPtr = gcnew Interop::QBXMLRP2::RequestProcessor3();

	try {
		rqPtr->OpenConnection2("", "QtrBk", Interop::QBXMLRP2::QBXMLRPConnectionType::localQBD);
		ticket = rqPtr->BeginSession2("", Interop::QBXMLRP2::QBFileMode::qbFileOpenDoNotCare);
		response = rqPtr->ProcessRequest(ticket, request);
		rqPtr->EndSession(ticket);
	}
	catch (Runtime::InteropServices::COMException^) {
		qb->error = responseToChars("Handled exception: " + rqPtr->GetQBLastError());
		qb->err = 1;
	}
	finally {
		try {
			rqPtr->CloseConnection();
		}
		catch (System::Exception^) {
			qb->error = responseToChars("Exception thrown while closing connection.");
			qb->err = 1;
		}
	}

	if (response != nullptr) {
		qb->response = responseToChars(response);
	}
	else {
		qb->error = responseToChars("Empty response");
		qb->err = 1;
	}
}

const char * responseToChars(String ^ response)
{
	pin_ptr<const wchar_t> wch = PtrToStringChars(response);
	size_t convertedChars = 0;
	size_t sizeInBytes = ((response->Length + 1) * 2);
	errno_t err = 0;
	char *ch = (char *)(malloc(sizeInBytes));
	err = wcstombs_s(&convertedChars, ch, sizeInBytes, wch, sizeInBytes);
	if (err != 0) {
		// do something here
	}
	return ch;
}
