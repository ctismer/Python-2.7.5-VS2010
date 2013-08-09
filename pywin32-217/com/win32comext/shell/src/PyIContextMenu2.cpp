// This file implements the IContextMenu Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "PyIContextMenu2.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGContextMenu2::QueryContextMenu(HMENU hmenu,
	UINT indexMenu,
	UINT idCmdFirst,
	UINT idCmdLast,
	UINT uFlags) {
	return PyGContextMenu::QueryContextMenu(hmenu, indexMenu, idCmdFirst,
						idCmdLast, uFlags);
}

STDMETHODIMP PyGContextMenu2::InvokeCommand(CMINVOKECOMMANDINFO * lpici) {
	return PyGContextMenu::InvokeCommand(lpici);
}

STDMETHODIMP PyGContextMenu2::GetCommandString(
	UINT_PTR idCmd,
	UINT uType,
	UINT     __RPC_FAR * pwReserved,
	LPSTR pszName,
	UINT cchMax) {
	return PyGContextMenu::GetCommandString(idCmd, uType, pwReserved,
						pszName, cchMax);
}

STDMETHODIMP PyGContextMenu2::HandleMenuMsg( 
                UINT uMsg,
                WPARAM wParam,
                LPARAM lParam)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("HandleMenuMsg", NULL, "INN", uMsg,
				   PyWinObject_FromPARAM(wParam),
				   PyWinObject_FromPARAM(lParam));
	if (FAILED(hr)) return hr;
	return S_OK;
}
