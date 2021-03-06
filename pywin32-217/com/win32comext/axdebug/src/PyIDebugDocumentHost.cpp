// This file implements the IDebugDocumentHost Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIDebugDocumentHost.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIDebugDocumentHost::PyIDebugDocumentHost(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIDebugDocumentHost::~PyIDebugDocumentHost()
{
}

/* static */ IDebugDocumentHost *PyIDebugDocumentHost::GetI(PyObject *self)
{
	return (IDebugDocumentHost *)PyIUnknown::GetI(self);
}

// @pymethod |PyIDebugDocumentHost|GetDeferredText|Description of GetDeferredText.
PyObject *PyIDebugDocumentHost::GetDeferredText(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	// @pyparm int|dwTextStartCookie||Description for dwTextStartCookie
	// @pyparm int|cMaxChars||Description for cMaxChars
	DWORD dwTextStartCookie;
	SOURCE_TEXT_ATTR pstaTextAttr;
	ULONG cMaxChars;
	if ( !PyArg_ParseTuple(args, "ll:GetDeferredText", &dwTextStartCookie, &cMaxChars) )
		return NULL;
	OLECHAR *pText = new OLECHAR [cMaxChars+1];
	SOURCE_TEXT_ATTR *pAttr = new SOURCE_TEXT_ATTR[cMaxChars+1];
	ULONG nChars = 0;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->GetDeferredText( dwTextStartCookie, pText, &pstaTextAttr, &nChars, cMaxChars );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return SetPythonCOMError(self, hr);
	PyObject *obpcharText = PyWinObject_FromOLECHAR(pText, nChars);
	PyObject *obattr;
	if (pAttr) {
		obattr = PyAXDebug_PyObject_FromSOURCE_TEXT_ATTR(pAttr, nChars);
	} else {
		obattr = Py_None;
		Py_INCREF(Py_None);
	}
	PyObject *pyretval = Py_BuildValue("OO", obpcharText, obattr);
	Py_XDECREF(obpcharText);
	Py_XDECREF(obattr);
	delete [] pText;
	delete [] pAttr;
	return pyretval;
}

// @pymethod |PyIDebugDocumentHost|GetScriptTextAttributes|Description of GetScriptTextAttributes.
PyObject *PyIDebugDocumentHost::GetScriptTextAttributes(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	// @pyparm <o unicode>|pstrCode||Description for pstrCode
	// @pyparm <o unicode>|pstrDelimiter||Description for pstrDelimiter
	// @pyparm int|dwFlags||Description for dwFlags
	PyObject *obpstrCode;
	PyObject *obpstrDelimiter;
	BSTR pstrCode;
	BSTR pstrDelimiter;
	DWORD dwFlags;
	if ( !PyArg_ParseTuple(args, "OOi:GetScriptTextAttributes", &obpstrCode, &obpstrDelimiter, &dwFlags) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obpstrCode, &pstrCode)) bPythonIsHappy = FALSE;
	ULONG len = SysStringLen(pstrCode);
	if (!PyCom_BstrFromPyObject(obpstrDelimiter, &pstrDelimiter)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	SOURCE_TEXT_ATTR *pAttr = new SOURCE_TEXT_ATTR[len+1];
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->GetScriptTextAttributes( pstrCode, len, pstrDelimiter, dwFlags, pAttr );
	if (pstrCode) SysFreeString(pstrCode);
	if (pstrDelimiter) SysFreeString(pstrDelimiter);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);
	return PyAXDebug_PyObject_FromSOURCE_TEXT_ATTR(pAttr, len);
}

// @pymethod |PyIDebugDocumentHost|OnCreateDocumentContext|Description of OnCreateDocumentContext.
PyObject *PyIDebugDocumentHost::OnCreateDocumentContext(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	IUnknown *ppunkOuter;
	if ( !PyArg_ParseTuple(args, ":OnCreateDocumentContext") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->OnCreateDocumentContext( &ppunkOuter );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);
	PyObject *obppunkOuter;

	obppunkOuter = PyCom_PyObjectFromIUnknown(ppunkOuter, IID_IUnknown, FALSE);
	PyObject *pyretval = Py_BuildValue("O", obppunkOuter);
	Py_XDECREF(obppunkOuter);
	return pyretval;
}

// @pymethod |PyIDebugDocumentHost|GetPathName|Description of GetPathName.
PyObject *PyIDebugDocumentHost::GetPathName(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	BSTR pbstrLongName;
	BOOL pfIsOriginalFile;
	if ( !PyArg_ParseTuple(args, ":GetPathName") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->GetPathName( &pbstrLongName, &pfIsOriginalFile );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);
	PyObject *obpbstrLongName;

	obpbstrLongName = MakeBstrToObj(pbstrLongName);
	PyObject *pyretval = Py_BuildValue("Oi", obpbstrLongName, pfIsOriginalFile);
	Py_XDECREF(obpbstrLongName);
	SysFreeString(pbstrLongName);
	return pyretval;
}

// @pymethod |PyIDebugDocumentHost|GetFileName|Description of GetFileName.
PyObject *PyIDebugDocumentHost::GetFileName(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	BSTR pbstrShortName;
	if ( !PyArg_ParseTuple(args, ":GetFileName") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->GetFileName( &pbstrShortName );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);
	PyObject *obpbstrShortName;

	obpbstrShortName = MakeBstrToObj(pbstrShortName);
	PyObject *pyretval = Py_BuildValue("O", obpbstrShortName);
	Py_XDECREF(obpbstrShortName);
	SysFreeString(pbstrShortName);
	return pyretval;
}

// @pymethod |PyIDebugDocumentHost|NotifyChanged|Description of NotifyChanged.
PyObject *PyIDebugDocumentHost::NotifyChanged(PyObject *self, PyObject *args)
{
	IDebugDocumentHost *pIDDH = GetI(self);
	if ( pIDDH == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":NotifyChanged") )
		return NULL;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIDDH->NotifyChanged( );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIDebugDocumentHost|Description of the interface
static struct PyMethodDef PyIDebugDocumentHost_methods[] =
{
	{ "GetDeferredText", PyIDebugDocumentHost::GetDeferredText, 1 }, // @pymeth GetDeferredText|Description of GetDeferredText
	{ "GetScriptTextAttributes", PyIDebugDocumentHost::GetScriptTextAttributes, 1 }, // @pymeth GetScriptTextAttributes|Description of GetScriptTextAttributes
	{ "OnCreateDocumentContext", PyIDebugDocumentHost::OnCreateDocumentContext, 1 }, // @pymeth OnCreateDocumentContext|Description of OnCreateDocumentContext
	{ "GetPathName", PyIDebugDocumentHost::GetPathName, 1 }, // @pymeth GetPathName|Description of GetPathName
	{ "GetFileName", PyIDebugDocumentHost::GetFileName, 1 }, // @pymeth GetFileName|Description of GetFileName
	{ "NotifyChanged", PyIDebugDocumentHost::NotifyChanged, 1 }, // @pymeth NotifyChanged|Description of NotifyChanged
	{ NULL }
};

PyComTypeObject PyIDebugDocumentHost::type("PyIDebugDocumentHost",
		&PyIUnknown::type,
		sizeof(PyIDebugDocumentHost),
		PyIDebugDocumentHost_methods,
		GET_PYCOM_CTOR(PyIDebugDocumentHost));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGDebugDocumentHost::GetDeferredText(
		/* [in] */ DWORD dwTextStartCookie,
		/* [size_is][length_is][out][in] */ WCHAR __RPC_FAR * pcharText,
		/* [size_is][length_is][out][in] */ SOURCE_TEXT_ATTR __RPC_FAR * pstaTextAttr,
		/* [out][in] */ ULONG __RPC_FAR * pcNumChars,
		/* [in] */ ULONG cMaxChars)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetDeferredText", &result, "iii", dwTextStartCookie, cMaxChars, (pstaTextAttr!=NULL));
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obText, *obAttr;
	if (!PyArg_ParseTuple(result, "OO" , &obText, &obAttr))
		 return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BSTR bstr;
	BOOL ok = TRUE;
	ok = PyCom_BstrFromPyObject(obText, &bstr);
	if (ok) {
		*pcNumChars = SysStringLen(bstr);
		wcsncpy(pcharText, bstr, *pcNumChars);
		SysFreeString(bstr);
	}
	if (ok && pstaTextAttr) {
		ok = PyAXDebug_PyObject_AsSOURCE_TEXT_ATTR(obAttr, pstaTextAttr, *pcNumChars);
	}
	Py_DECREF(result);
	if (!ok)
		 return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	return hr;
}

STDMETHODIMP PyGDebugDocumentHost::GetScriptTextAttributes(
		/* [size_is][in] */ LPCOLESTR pstrCode,
		/* [in] */ ULONG uNumCodeChars,
		/* [in] */ LPCOLESTR pstrDelimiter,
		/* [in] */ DWORD dwFlags,
		/* [size_is][out][in] */ SOURCE_TEXT_ATTR __RPC_FAR * pattr)
{
	PY_GATEWAY_METHOD;
	PyObject *obpstrCode;
	PyObject *obpstrDelimiter;
	obpstrCode = PyWinObject_FromOLECHAR(pstrCode,uNumCodeChars);
	obpstrDelimiter = PyWinObject_FromOLECHAR(pstrDelimiter);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetScriptTextAttributes", &result, "OOi", obpstrCode, obpstrDelimiter, dwFlags);
	Py_XDECREF(obpstrCode);
	Py_XDECREF(obpstrDelimiter);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyAXDebug_PyObject_AsSOURCE_TEXT_ATTR(result, pattr, uNumCodeChars))
		hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDebugDocumentHost::OnCreateDocumentContext(
		/* [out] */ IUnknown __RPC_FAR *__RPC_FAR * ppunkOuter)
{
	PY_GATEWAY_METHOD;
	if (ppunkOuter==NULL) return E_POINTER;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("OnCreateDocumentContext", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppunkOuter;
	if (!PyArg_Parse(result, "O" , &obppunkOuter)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obppunkOuter, IID_IUnknown, (void **)ppunkOuter, FALSE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDebugDocumentHost::GetPathName(
		/* [out] */ BSTR __RPC_FAR * pbstrLongName,
		/* [out] */ BOOL __RPC_FAR * pfIsOriginalFile)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetPathName", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obpbstrLongName;
	if (!PyArg_ParseTuple(result, "Oi" , &obpbstrLongName, pfIsOriginalFile)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obpbstrLongName, pbstrLongName)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDebugDocumentHost::GetFileName(
		/* [out] */ BSTR __RPC_FAR * pbstrShortName)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetFileName", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obpbstrShortName;
	if (!PyArg_Parse(result, "O" , &obpbstrShortName)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyCom_BstrFromPyObject(obpbstrShortName, pbstrShortName)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDebugDocumentHost::NotifyChanged(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("NotifyChanged", NULL);
	return hr;
}

