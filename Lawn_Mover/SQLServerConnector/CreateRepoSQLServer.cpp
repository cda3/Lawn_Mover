#include "pch.h"
#include "CreateRepoSQLServer.h"
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

void CreateRepoSQLServer::addReport(std::string path)
{
	SQLHANDLE SQLEnvHandle = nullptr;
	SQLHANDLE SQLConnectionHandle = nullptr;
	SQLHANDLE SQLStatementHandle = nullptr;
	SQLRETURN retCode = 0;

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
		throw std::exception();

	if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		throw std::exception();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
		throw std::exception();

	if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		throw std::exception();

	SQLWCHAR retConString[1024]; // Conection string
	switch (SQLDriverConnect(SQLConnectionHandle, nullptr, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=10.112.109.225, 1433;DATABASE=ICONIS;Trusted=true;",
		SQL_NTS, retConString, 1024, nullptr, SQL_DRIVER_COMPLETE))
	{
		// Establishes connections to a driver and a data source
	case SQL_SUCCESS:
		break;
	case SQL_SUCCESS_WITH_INFO:
		break;
	case SQL_NO_DATA_FOUND:
		retCode = -1;
		break;
	case SQL_INVALID_HANDLE:
		retCode = -1;
		break;
	case SQL_ERROR:
		retCode = -1;
		break;
	default:
		break;
	}

	if (retCode == -1)
	{
		throw std::exception();
	}

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
		throw std::exception();

	auto u1 = "INSERT INTO[configuration].CandidaRepo([description]) VALUES('Deleted file: ";
	auto u3 = "')";
	auto command = u1 + path + u3;
	std::wstring wcommand = std::wstring(command.begin(), command.end());
	const wchar_t* wcharcommand = wcommand.c_str();

	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)wcharcommand, SQL_NTS))
	{
		throw std::exception();
	}
}



