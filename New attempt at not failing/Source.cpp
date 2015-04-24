//Sql.cpp
#include  <windows.h>
#include  <string>
#include  <cstdio>
#include  <odbcinst.h>
#include  <sqltypes.h>
#include  <sql.h>
#include  <sqlext.h>
#include  "MySql.h"


SQL::SQL() //Constructor
{
	ZeroMemory(szCnOut, 512);
	ZeroMemory(szErrMsg, 512);
	strDBQ = "";
}


SQL::~SQL()
{
	//Sql Destructor
}


void SQL::MakeConnectionString(void)
{
	if (strDriver == "SQL Server")
	{
		if (strDBQ == "")
		{
			strConnectionString = "DRIVER=";
			strConnectionString = strConnectionString + strDriver + ";" + "SERVER=" + strServer + ";";
		}
		else
		{
			strConnectionString = "DRIVER=";
			strConnectionString = strConnectionString + strDriver + ";" + "SERVER=" + strServer + ";" + \
				"DATABASE=" + strDatabase + ";" + "DBQ=" + strDBQ + ";";
		}
	}
	else if (strDriver == "Microsoft Access Driver (*.mdb)")
	{
		strConnectionString = "DRIVER=";
		strConnectionString = strConnectionString + strDriver + ";" + "DBQ=" + strDBQ + ";";
	}
	else if (strDriver == "Microsoft Excel Driver (*.xls)")
	{
		strConnectionString = "DRIVER=";
		strConnectionString = strConnectionString + strDriver + ";" + "DBQ=" + strDBQ + ";";
	}
}


void SQL::ODBCConnect(void)
{
	char szCnIn[512];
	unsigned int iResult;

	MakeConnectionString();
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnvr);
	SQLSetEnvAttr(hEnvr, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, hEnvr, &hConn);
	strcpy_s(szCnIn, strConnectionString.c_str());
	iResult = SQLDriverConnect(hConn, NULL, (SQLTCHAR*)szCnIn, (SQLSMALLINT)strlen(szCnIn), (SQLTCHAR*)szCnOut, 512, &swStrLen, SQL_DRIVER_NOPROMPT);
	if (iResult == 0 || iResult == 1)
		blnConnected = TRUE;
	else
	{
		SQLGetDiagRec(SQL_HANDLE_DBC, hConn, 1, szErrCode, &iNativeErrPtr, szErrMsg, 512, &iTextLenPtr);
		blnConnected = FALSE;
		SQLDisconnect(hConn);
		SQLFreeHandle(SQL_HANDLE_DBC, hConn);
		SQLFreeHandle(SQL_HANDLE_ENV, hEnvr);
	}
}


void SQL::ODBCDisconnect(void)
{
	if (blnConnected == TRUE)
	{
		SQLDisconnect(hConn);
		SQLFreeHandle(SQL_HANDLE_DBC, hConn);
		SQLFreeHandle(SQL_HANDLE_ENV, hEnvr);
		blnConnected = FALSE;
	}
}
